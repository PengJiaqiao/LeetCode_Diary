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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v = {};
        if(root == NULL) return v;
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        while(ptr || !s.empty()) {
            while(ptr) {
                s.push(ptr);
                ptr = ptr->left;
            }
            ptr = s.top();
            s.pop();
            v.push_back(ptr->val);
            ptr = ptr->right;
        }
        return v;
    }
};
