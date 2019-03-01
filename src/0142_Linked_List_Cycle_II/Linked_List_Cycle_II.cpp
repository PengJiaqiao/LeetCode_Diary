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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* slow = fakehead;
        ListNode* faster = fakehead;
        while (faster && faster->next){
            slow = slow->next;
            faster = faster->next->next;
            if (slow == faster) break;
        }
        if (faster == NULL || faster->next == NULL) return NULL;
        
        ListNode* ptr1 = fakehead;
        ListNode* ptr2 = slow;
        while (ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
