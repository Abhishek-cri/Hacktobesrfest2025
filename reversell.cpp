#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        // Traverse the list and reverse the links
        while (head != nullptr) {
            next = head->next;   // store next node
            head->next = prev;   // reverse current node's pointer
            prev = head;         // move prev one step forward
            head = next;         // move head one step forward
        }
        return prev;  // prev will be the new head of reversed list
    }
};

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* newHead = s.reverseList(head);

    // Print the reversed linked list
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
