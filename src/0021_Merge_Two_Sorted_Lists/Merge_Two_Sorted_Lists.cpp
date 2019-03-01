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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* temp;
        if (ptr1->val < ptr2->val) {
            ptr1->next = mergeTwoLists(ptr1->next, ptr2);
            return ptr1;
        }
        else {
            ptr2->next = mergeTwoLists(ptr1, ptr2->next);
            return ptr2;
        }
    }
};
