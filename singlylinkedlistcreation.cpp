#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Insert at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    std::cout << "Enter elements for the linked list (enter -1 to stop):" << std::endl;

    int element;
    while (true) {
        std::cin >> element;
        if (element == -1) {
            break;
        }
        linkedList.insertAtEnd(element);
    }

    std::cout << "Created Linked List:" << std::endl;
    linkedList.display();

    return 0;
}
