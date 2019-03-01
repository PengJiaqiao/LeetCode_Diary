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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        
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
            middle = slow->next;
            slow->next = NULL;
            middle = reverseList(middle);
        }
        else {
            middle = reverseList(slow->next);
            slow->next = NULL;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = middle;
        ListNode* temp1;
        ListNode* temp2;
        while (ptr2){
            temp1 = ptr1->next;
            ptr1->next = ptr2;
            temp2 = ptr2->next;
            ptr2->next = temp1;
            ptr1 = temp1;
            ptr2 = temp2;
        }
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
