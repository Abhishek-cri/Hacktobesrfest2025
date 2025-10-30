#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to remove Nth node from end
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* first = dummy;
    Node* second = dummy;

    // Move first n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        if (first == NULL) return head; // if n > length of list
        first = first->next;
    }

    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // Delete the target node
    Node* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    return dummy->next;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:\n";
    printList(head);

    int n = 2; // remove 2nd node from end
    head = removeNthFromEnd(head, n);

    cout << "\nList after removing " << n << "th node from end:\n";
    printList(head);

    return 0;
}
