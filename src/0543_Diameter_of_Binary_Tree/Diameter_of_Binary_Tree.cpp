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
    int max = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return max;
    }
private:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int sum = leftDepth + rightDepth;
        max = sum > max ? sum : max;
        return (leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1);
    }
};
