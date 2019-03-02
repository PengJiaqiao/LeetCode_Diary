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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        maxDepth(root, &result);
        return result;
    }
private:
    int maxDepth(TreeNode* root, bool* result) {
        if (root == NULL) return 0;
        int leftDepth = maxDepth(root->left, result);
        int rightDepth = maxDepth(root->right, result);
        if (abs(leftDepth - rightDepth) > 1) *result = false;
        return (leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1);
    }
};
