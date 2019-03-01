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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> s1;
        stack <int> s2;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* cur;
        ListNode* post = NULL;
        int sum;
        int carry = 0;
        
        while (ptr1) {
            s1.push(ptr1->val);
            ptr1 = ptr1->next;
        }
        while (ptr2) {
            s2.push(ptr2->val);
            ptr2 = ptr2->next;
        }
        
        while (!s1.empty() || !s2.empty() || carry){
            sum = (s1.empty()? 0 : s1.top()) + (s2.empty()? 0 : s2.top()) + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            cur = new ListNode(sum);
            cur->next = post;
            post = cur;
        }
        
        return cur;
    }
};
