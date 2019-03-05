/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int> v;
        ListNode* ptr = head;
        while(ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        return sortedArrayToBST(v);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return BuildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* BuildBST(vector<int>& nums, int sIdx, int eIdx) {
        int range = eIdx - sIdx;
        int l = range / 2;
        int r = range - l;
        TreeNode* root = new TreeNode(nums[sIdx + l]);
        if(l) root->left = BuildBST(nums, sIdx, sIdx + l - 1);
        if(r) root->right = BuildBST(nums, sIdx + l + 1, eIdx);
        return root;
    }
};
