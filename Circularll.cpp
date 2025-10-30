#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    // Create nodes
    ListNode* a = new ListNode{1, NULL};
    ListNode* b = new ListNode{2, NULL};
    ListNode* c = new ListNode{3, NULL};
    ListNode* d = new ListNode{4, NULL};

    // Link them: 1 -> 2 -> 3 -> 4
    a->next = b;
    b->next = c;
    c->next = d;
    if (hasCycle(a))
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}
