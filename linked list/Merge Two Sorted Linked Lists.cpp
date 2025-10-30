#include <bits/stdc++.h>
using namespace std;

// Linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Merge two sorted linked lists
Node* mergeLists(Node* l1, Node* l2) {
    // Dummy node to start the merged list
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy->next; // Return head of merged list
}

// Helper to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First sorted linked list: 1 -> 3 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    // Second sorted linked list: 2 -> 4 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Node* merged = mergeLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}


// output
// List 1: 1 3 5
// List 2: 2 4 6
// Merged List: 1 2 3 4 5 6
