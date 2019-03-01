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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* slow = fakehead;
        ListNode* faster = fakehead;
        while (faster && faster->next){
            slow = slow->next;
            faster = faster->next->next;
            if (slow == faster) return true;
        }
        return false;
    }
};
