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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        dfs(root);
        return root;
    }
private:
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->right);
        root->val = root->val + sum;
        sum = root->val;
        dfs(root->left);
    }
};
