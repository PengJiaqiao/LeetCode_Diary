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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next == NULL || m == n)return head;
        ListNode* start;
        if(m > 1) start = head;
        else {
            start = new ListNode(0);
            start->next = head;
        }
        
        for(int i = 2; i < m; i++){
            start = start->next;
        }
        
        ListNode* node1 = start->next;
        ListNode* node2 = node1->next;
        
        for (int i = 0; i < n - m; i++){
            node1->next = node2->next;
            node2->next = start->next;
            start->next = node2;
            node2 = node1->next;
        }
        
        return (m > 1? head : start->next);
    }
};
