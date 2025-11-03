/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        int len1 = countNodes(headA);
        int len2 = countNodes(headB);

        int difference = abs(len1 - len2);

        ListNode* current1 = headA;
        ListNode* current2 = headB;

        if(len1 > len2) {
            for(int i = 0; i < difference; ++i) {
                current1 = current1->next;
            }
        }
        else {
            for(int i = 0; i < difference; ++i) {
                current2 = current2->next;
            }
        }

        while(current1 != nullptr && current2 != nullptr) {
            if(current1 == current2) {
                return current1;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return nullptr;
    }
};
