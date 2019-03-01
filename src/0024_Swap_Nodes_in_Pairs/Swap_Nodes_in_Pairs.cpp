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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head->next;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* temp;
        while(node2->next && node2->next->next){
            node1->next = node2->next->next;
            temp = node1;
            node1 = node2->next;
            node2->next = temp;
            node2 = node1->next;
        }
        if (node2->next == NULL) {
            node1->next = NULL;
            node2->next = node1;
        } 
        else {
            node1->next = node2->next;
            node2->next = node1;
        }
        
        return fakehead->next;
    }
};
