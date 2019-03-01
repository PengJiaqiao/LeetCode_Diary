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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* pre = fakehead;
        ListNode* cur = head;
        ListNode* post = head->next;
        int length = 0;
        for (ListNode* count = head; count != NULL;){
            length++;
            count = count->next;
        }
        
        int k_ = length / k;
        for (int i = 0; i < k_; i++){
            for (int j = 0; j < k - 1; j++){
                cur->next = post->next;
                post->next = pre->next;
                pre->next = post;
                post = cur->next;
            }
            if (i != k_ - 1){
                pre = cur;
                cur = post;
                post = post->next;
            }
        }
        
        return fakehead->next;
    }
};
