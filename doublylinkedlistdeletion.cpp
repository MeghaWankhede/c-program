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

    // Delete a node with a given value from the list
    void deleteNode(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
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

    std::cout << "Enter elements for the doubly linked list (enter -1 to stop):" << std::endl;

    int element;
    while (true) {
        std::cin >> element;
        if (element == -1) {
            break;
        }
        doublyLinkedList.insertAtEnd(element);
    }

    std::cout << "Created Doubly Linked List:" << std::endl;
    doublyLinkedList.display();

    std::cout << "Enter an element to delete (or -1 to stop):" << std::endl;

    while (true) {
        std::cin >> element;
        if (element == -1) {
            break;
        }
        doublyLinkedList.deleteNode(element);
        std::cout << "Updated Doubly Linked List:" << std::endl;
        doublyLinkedList.display();
    }

    return 0;
}
