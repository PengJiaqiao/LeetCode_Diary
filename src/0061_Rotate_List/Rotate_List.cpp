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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)return head;
        
        ListNode* p = head;
        int length = 0;
        while (p){
            length++;
            p = p->next;
        }
        
        int k_ = k % length;
        if (k_ == 0) return head;
        p = head;
        for (int i = 1; i < length - k_; i++){
            p = p->next;
        }
        
        ListNode* tail = p->next;
        p->next = NULL;
        for (p = tail; p->next != NULL;){
            p = p->next;
        }
        p->next = head;
        
        return tail;
    }
};
