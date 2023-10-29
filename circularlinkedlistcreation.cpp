#include <iostream>

// Define a struct for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (!head) {
        newNode->next = newNode; // Point to itself for the first node
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode; // Update the head to the new node
    }

    return head;
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (!head)
        return;

    Node* current = head;

    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    std::cout << " (Back to the beginning)" << std::endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    std::cout << "Circular Linked List: ";
    displayList(head);

    return 0;
}
