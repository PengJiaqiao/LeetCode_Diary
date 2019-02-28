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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        
        ListNode* node1 = head;
        ListNode* node2 = head;
        for (int i = 0; i < n; i++){
            node2 = node2->next;
        }
        if (node2 == NULL) return head->next;
        
        while (node2->next){
            node1 = node1->next;
            node2 = node2->next;
        }
        node1->next = node1->next->next;
        
        return head;
    }
};
