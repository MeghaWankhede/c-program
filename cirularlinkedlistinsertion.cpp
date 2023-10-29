#include <iostream>

// Define a struct for the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the circular linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    
    if (!head) {
        newNode->next = newNode; // Point to itself for the first node
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    
    return newNode;
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

    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    std::cout << "Circular Linked List: ";
    displayList(head);

    return 0;
}
