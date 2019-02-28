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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)return head;
        
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* pre = fakehead;
        ListNode* cur = head;
        ListNode* post = head->next;
        bool del_flag = false;
        
        while(post){
            if (cur->val == post->val) {
                del_flag = true;
                post = post->next;
                if (!post) pre->next = NULL;
            }
            else {
                if (del_flag) {
                    pre->next = post;
                    del_flag = false;
                }
                else pre = cur;
                
                cur = post;
                post = post->next;
            }
        }
        return fakehead->next;
    }
};
