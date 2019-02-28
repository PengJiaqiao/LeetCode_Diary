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
    ListNode* partition(ListNode* head, int x) {
        ListNode LessHead(0), *les = &LessHead;
        ListNode GreHead(0), *gre = &GreHead;//greater than or equal to x.
        ListNode* p = head;
        
        while(p){
            if(p->val < x){
                les->next = new ListNode(p->val);
                les = les->next;
            }
            else {
                gre->next = new ListNode(p->val);
                gre= gre->next;
            }
            p = p->next;
        }
        les->next = GreHead.next;
            
        return LessHead.next;
    }
};
