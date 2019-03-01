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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* slow = fakehead;
        ListNode* faster = fakehead;
        ListNode* middle;
        while (faster != NULL && faster->next != NULL){
            slow = slow->next;
            faster = faster->next->next;
        }
        
        if (faster == NULL){
            middle = new ListNode(slow->val);
            middle->next = slow->next;
            slow->next = NULL;
            middle = reverseList(middle);
        }
        else {
            middle = reverseList(slow->next);
            slow->next = NULL;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = middle;
        while (ptr1){
            if (ptr1->val != ptr2->val) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode* p = new ListNode(head->val);
        while(head->next){
            head = head->next;
            p = AddPreNode(head, p);
        }
        return p;
    }
    ListNode* AddPreNode(ListNode* pre, ListNode* tail) {
        ListNode* head = new ListNode(pre->val);
        head->next = tail;
        return head;
    }
};
