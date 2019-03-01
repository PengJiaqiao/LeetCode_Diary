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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        int isEnd = 0;
        while(ptr1 != ptr2){
            if (ptr1->next == NULL) {
                ptr1 = headB;
                isEnd++;
            }
            else ptr1 = ptr1->next;
            if (isEnd == 2) return NULL;
            
            ptr2 = ptr2->next == NULL? headA : ptr2->next;
        }
        
        return ptr1;
    }
};
