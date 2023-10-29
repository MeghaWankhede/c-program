#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at a specific position in the list
    void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;
        int count = 0;

        while (current) {
            if (count == position) {
                newNode->prev = current->prev;
                newNode->next = current;
                if (current->prev) {
                    current->prev->next = newNode;
                } else {
                    head = newNode;
                }
                current->prev = newNode;
                return;
            }
            current = current->next;
            count++;
        }

        // If the position is beyond the end of the list, insert at the end.
        insertAtEnd(data);
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList doublyLinkedList;

    doublyLinkedList.insertAtEnd(1);
    doublyLinkedList.insertAtEnd(2);
    doublyLinkedList.insertAtEnd(3);

    std::cout << "Initial Doubly Linked List:" << std::endl;
    doublyLinkedList.display();

    doublyLinkedList.insertAtBeginning(0);
    doublyLinkedList.insertAtPosition(2.5, 2);

    std::cout << "\nModified Doubly Linked List:" << std::endl;
    doublyLinkedList.display();

    return 0;
}
