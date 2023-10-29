#include <iostream>

class CircularQueue {
private:
    int* array;
    int capacity;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        capacity = size;
        array = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] array;
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the circular queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to enqueue (push) an element into the circular queue
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        array[rear] = value;
        std::cout << "Enqueued " << value << " into the circular queue." << std::endl;
    }

    // Function to dequeue (pop) an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a sentinel value to indicate an empty queue
        }

        int value = array[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return value;
    }
};

int main() {
    CircularQueue circularQueue(5);

    circularQueue.enqueue(1);
    circularQueue.enqueue(2);
    circularQueue.enqueue(3);

    std::cout << "Dequeued: " << circularQueue.dequeue() << std::endl;
    std::cout << "Dequeued: " << circularQueue.dequeue() << std::endl;

    circularQueue.enqueue(4);
    circularQueue.enqueue(5);

    while (!circularQueue.isEmpty()) {
        std::cout << "Dequeued: " << circularQueue.dequeue() << std::endl;
    }

    return 0;
}
