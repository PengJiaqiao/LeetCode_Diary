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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode* p = new ListNode(head->val);
        while(head->next){
            head = head->next;
            p = AddPreNode(head, p);
        }
        return p;
    }
private:
    ListNode* AddPreNode(ListNode* pre, ListNode* tail) {
        ListNode* head = new ListNode(pre->val);
        head->next = tail;
        return head;
    }
};
