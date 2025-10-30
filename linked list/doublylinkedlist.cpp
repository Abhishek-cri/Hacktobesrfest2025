#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
            return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (!head)
            return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dl;
    dl.insertAtEnd(10);
    dl.insertAtEnd(20);
    dl.insertAtEnd(30);
    dl.insertAtEnd(40);

    dl.displayForward();
    dl.displayBackward();

    dl.deleteNode(20);
    cout << "After deleting 20:\n";
    dl.displayForward();

    return 0;
}
