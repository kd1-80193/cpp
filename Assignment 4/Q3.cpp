#include <iostream>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

public:
    // Parameter-less constructor
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // Parameterized constructor
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new int[cols];
        }
    }

    // Destructor to release dynamically allocated memory
    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    // Function to accept matrix values
    void accept()
    {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Enter element at row " << i + 1 << ", col " << j + 1 << ": ";
                cin >> data[i][j];
            }
        }
    }

    // Function to print matrix
    void print()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix add(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cerr << "Matrix dimensions do not match for addition." << endl;
            return Matrix(); // Return an empty matrix
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Function to subtract two matrices
    Matrix subtract(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cerr << "Matrix dimensions do not match for subtraction." << endl;
            return Matrix(); // Return an empty matrix
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Function to multiply two matrices
    Matrix multiply(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            cerr << "Matrix dimensions are incompatible for multiplication." << endl;
            return Matrix(); // Return an empty matrix
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to transpose the matrix
    Matrix transpose() const
    {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main()
{
    int numRows, numCols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> numRows >> numCols;

    Matrix mat1(numRows, numCols);
    Matrix mat2(numRows, numCols);

    cout << "Matrix 1:" << endl;
    mat1.accept();

    cout << "Matrix 2:" << endl;
    mat2.accept();

    cout << "Matrix 1:" << endl;
    mat1.print();

    cout << "Matrix 2:" << endl;
    mat2.print();

    Matrix sum = mat1.add(mat2);
    Matrix difference = mat1.subtract(mat2);
    Matrix product = mat1.multiply(mat2);
    Matrix transposed = mat1.transpose();

    cout << "Sum of matrices:" << endl;
    sum.print();

    cout << "Difference of matrices:" << endl;
    difference.print();

    cout << "Product of matrices:" << endl;
    product.print();

    cout << "Transpose of Matrix 1:" << endl;
    transposed.print();

    return 0;
}
