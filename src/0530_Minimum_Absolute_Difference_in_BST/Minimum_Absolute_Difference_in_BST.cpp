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
    vector<int> v;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return v[1];
    }
private:
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        if(v.empty()) {
            v.push_back(root->val);
            v.push_back(2147483647);
           // v[1] = 2147483647;
        }
        else {
            int diff = root->val - v[0];
            v[1] = min(diff, v[1]);
            v[0] = root->val;
        }
        dfs(root->right);
        return;
    }
};
