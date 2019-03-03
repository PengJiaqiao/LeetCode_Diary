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
    int rob(TreeNode* root) {
        return res(root)[1];
    }
private:
    vector<int> res(TreeNode* root) {//Dynamic programming
        vector<int> res_ = {0, 0};//res_[0]: max from leaves to child; res_[1]: max from leaves to current node
        if (root != NULL) {
            vector<int> left = res(root->left);
            vector<int> right = res(root->right);
            res_[0] = left[1] + right[1];
            res_[1] = max(left[0] + right[0] + root->val, res_[0]);
        }
        return res_;
    }
};
