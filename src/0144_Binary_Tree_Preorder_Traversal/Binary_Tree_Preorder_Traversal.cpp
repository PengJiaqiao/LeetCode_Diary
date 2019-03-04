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
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector <int> v;
        TreeNode* ptr;
        if (root == NULL) return {};
        s.push(root);
        while(!s.empty()) {
            ptr = s.top();
            s.pop();
            while(ptr != NULL) {
                v.push_back(ptr->val);
                if(ptr->right != NULL) s.push(ptr->right);
                ptr = ptr->left;
            }
        }
        return v;
    }
};
