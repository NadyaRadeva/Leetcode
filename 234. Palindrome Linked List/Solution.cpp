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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *previous = nullptr, *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }
        return previous;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);

        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;
        bool palindrome = true;

        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverseList(secondHalfCopy);

        return palindrome;
    }
};
