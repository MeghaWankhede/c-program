#include <iostream>

class Queue {
private:
    int* array;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = rear = -1;
        this->size = 0;
    }

    ~Queue() {
        delete[] array;
    }

    // Function to enqueue (push) an element into the queue
    void enqueue(int value) {
        if (size == capacity) {
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }
        
        if (front == -1)
            front = 0;
        
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
        std::cout << "Enqueued " << value << " into the queue." << std::endl;
    }

    // Function to dequeue (pop) an element from the queue
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
        size--;
        return value;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to get the size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.enqueue(4);
    queue.enqueue(5);

    while (!queue.isEmpty()) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    return 0;
}
