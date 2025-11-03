/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int countNodes(ListNode* head) {
        int counter = 0;

        ListNode* current = head;

        while(current != nullptr) {
            ++counter;
            current = current->next;
        }

        return counter;
    }

    ListNode* middleNode(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        int total = countNodes(head);
        int midIndex = total / 2;

        ListNode* current = head;
        for (int i = 0; i < midIndex; ++i) {
            current = current->next;
        }

        return current;
    }
};
