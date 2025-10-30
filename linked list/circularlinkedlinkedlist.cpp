#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() { head = nullptr; }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insert(40);

    cout << "Circular Linked List: ";
    cl.display();

    return 0;
}
