#include <iostream>

class Stack {
private:
    int* array;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1; // Initialize the top of the stack
    }

    ~Stack() {
        delete[] array;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == capacity - 1) {
            std::cout << "Stack is full. Cannot push " << value << std::endl;
        } else {
            array[++top] = value;
            std::cout << "Pushed " << value << " onto the stack." << std::endl;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return -1; // Return a sentinel value to indicate an empty stack
        } else {
            int value = array[top--];
            return value;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Popped: " << stack.pop() << std::endl;
    std::cout << "Popped: " << stack.pop() << std::endl;

    stack.push(4);
    stack.push(5);

    while (!stack.isEmpty()) {
        std::cout << "Popped: " << stack.pop() << std::endl;
    }

    return 0;
}
