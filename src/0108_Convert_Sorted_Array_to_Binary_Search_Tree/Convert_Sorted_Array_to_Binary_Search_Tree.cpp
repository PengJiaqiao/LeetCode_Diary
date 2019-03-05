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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return BuildBST(nums, 0, nums.size() - 1);
    }
private:
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
