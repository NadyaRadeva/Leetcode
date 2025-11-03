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
 
    ListNode* reverse(ListNode* head) {
        ListNode *current = head, *previous = nullptr, *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }

        head = reverse(head);

        if (n == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } 
        else {
            ListNode* current = head;
            for (int i = 1; current != nullptr && i < n - 1; ++i) {
                current = current->next;
            }

            if (current != nullptr && current->next != nullptr) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }

        head = reverse(head);
        return head;
    }
};
