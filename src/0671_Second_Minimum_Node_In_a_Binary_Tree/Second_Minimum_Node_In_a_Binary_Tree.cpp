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
    int findSecondMinimumValue(TreeNode* root) {
        if (root->left == NULL) return -1;
        int min_ = min(root->left->val, root->right->val);
        if (root->val == min_) {
            int max_ = max(root->left->val, root->right->val);
            if (root->val == max_) {
                int l = findSecondMinimumValue(root->left);
                int r = findSecondMinimumValue(root->right);
                int res = min((l > 0? l : r), (r > 0? r : l));
                return (res < 0) ? -1 : res;
            }
            else {
                int res = root->left->val > root->right->val? findSecondMinimumValue(root->right) : findSecondMinimumValue(root->left);
                return res < 0? max_ : min(res, max_);
            }
        }
        else return min_;
    }
};
