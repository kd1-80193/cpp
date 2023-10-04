#include <iostream>

using namespace std;

class Stack
{
private:
    int *array; 
    int size;   
    int top;    
public:
    // Parameterized constructor to create a stack with a given size
    Stack(int stackSize = 5)
    {
        size = stackSize;
        array = new int[size];
        top = -1; // Initialize top to -1, indicating an empty stack
    }

    // Destructor to deallocate the dynamically allocated array
    ~Stack()
    {
        delete[] array;
    }

    // Push an element onto the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        array[++top] = value;
    }

    // Pop the top element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        --top;
    }

    // Peek at the top element without removing it
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return array[top];
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const
    {
        return top == size - 1;
    }

    // Print the elements in the stack
    void print() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (from top to bottom): ";
        for (int i = top; i >= 0; --i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Create a stack with a size of 5 (default size)
    Stack stack(5);

    // Push some elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the stack
    stack.print();

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Pop an element
    stack.pop();

    // Print the updated stack
    stack.print();

    return 0;
}
