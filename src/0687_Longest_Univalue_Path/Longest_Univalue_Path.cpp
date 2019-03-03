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
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
private:
    int res;
    
    int helper(TreeNode* root)
    {
        if (root == NULL) return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        int pl = 0, pr = 0;
        if (root->left and root->left->val == root->val) pl = l + 1;
        if (root->right and root->right->val == root->val) pr = r + 1;
        res = max(res, pl + pr);
        return max(pl, pr);
    }
};
