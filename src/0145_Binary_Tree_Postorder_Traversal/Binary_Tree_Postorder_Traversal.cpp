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
    vector<int> postorderTraversal(TreeNode* root) {//change preorder from root-left-right to root-right-left and reverse it
        stack <TreeNode*> s;
        vector <int> v;
        TreeNode* ptr;
        if (root == NULL) return {};
        s.push(root);
        while (!s.empty()) {
            ptr = s.top();
            s.pop();
            while(ptr != NULL) {
                v.push_back(ptr->val);
                if(ptr->left != NULL) s.push(ptr->left);
                ptr = ptr->right;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
