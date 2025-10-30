#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* detectCycle(ListNode* head) {
    if (head == NULL)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Check if cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // No cycle
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Step 2: Find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Create nodes
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);

    // Link nodes: 3 -> 2 -> 0 -> -4 -> (back to 2)
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  // makes a cycle

    ListNode* ans = detectCycle(a);

    if (ans != NULL)
        cout << "Cycle starts at node with value: " << ans->val;
    else
        cout << "No cycle detected";

    return 0;
}
