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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> v;
        ListNode* ptr = root;
        ListNode* temp = NULL;
        int count = 0;
        int i, j = 0;
        
        while (ptr) {
            count++;
            ptr = ptr->next;
        }
        
        if (k >= count) {
            ptr = root;
            for (i = 0; i < count; i++) {
                v.push_back(ptr);
                temp = ptr ->next;
                ptr->next = NULL;
                ptr = temp;
            }
            for (i = 0; i < k - count; i++) {
                v.push_back(NULL);
            }
        }
        else {
            int larger = count % k;
            int less = k - larger;
            ptr = root;
            
            for (i = 0; i < larger; i++) {
                v.push_back(ptr);
                for (j = 0; j < count/k; j++) {
                    ptr = ptr->next;
                }
                temp = ptr->next;
                ptr->next = NULL;
                ptr = temp;
            }
            
            for (i = 0; i < less; i++) {
                v.push_back(ptr);
                for  (j = 0; j < count/k - 1; j++) {
                    ptr = ptr->next;
                }
                temp = ptr->next;
                ptr->next = NULL;
                ptr = temp;
            }
        }
        return v;
    }
};
