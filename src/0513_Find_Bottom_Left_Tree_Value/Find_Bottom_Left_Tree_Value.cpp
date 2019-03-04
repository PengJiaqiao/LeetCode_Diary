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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue <TreeNode*> q;
        int n = 1; // number of each level
        int count = 0; // count number of next level
        TreeNode* ptr = root;
        q.push(root);
        while(!q.empty()) {
            ptr = q.front();
            res = ptr->val;
            for (int i = 0; i < n; i++) {
                ptr = q.front();
                q.pop();
                if(ptr->left != NULL) {
                    q.push(ptr->left);
                    count++;
                }
                if(ptr->right != NULL) {
                    q.push(ptr->right);
                    count++;
                }
            }
            n = count;
            count = 0;
        }
        return res;
    }
};
