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

    // Delete a node with a given value from the list
    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
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

    std::cout << "Enter an element to delete (or -1 to stop):" << std::endl;

    while (true) {
        std::cin >> element;
        if (element == -1) {
            break;
        }
        linkedList.deleteNode(element);
        std::cout << "Updated Linked List:" << std::endl;
        linkedList.display();
    }

    return 0;
}
