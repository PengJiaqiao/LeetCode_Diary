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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* ptr = new TreeNode(0);
        ptr->right = root;
        int count = 0;
        while(count != k) {
            ptr = ptr->right;
            while(ptr) {
                s.push(ptr);
                ptr = ptr->left;
            }
            ptr = s.top();
            s.pop();
            count++;
        }
        return ptr->val;
    }
};
