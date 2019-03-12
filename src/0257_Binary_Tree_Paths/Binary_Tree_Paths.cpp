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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        vector<string> res;
        string cur = to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            res.push_back(cur);
            return res;
        }
        vector<string> post_l = binaryTreePaths(root->left);
        vector<string> post_r = binaryTreePaths(root->right);
        for(string post : post_l) res.push_back(cur + "->" + post);
        for(string post : post_r) res.push_back(cur + "->" + post);
        return res;
    }
};
