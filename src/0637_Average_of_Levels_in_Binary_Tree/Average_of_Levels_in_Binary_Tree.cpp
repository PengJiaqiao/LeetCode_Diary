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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> v;
        queue <TreeNode*> q;
        int n = 1; // number of each level
        int count = 0; // count number of next level
        long sum = 0;
        TreeNode* ptr;
        if (root == NULL) {
            v.push_back(0);
            return v;
        }
        q.push(root);
        while(!q.empty()) {
            for (int i = 0; i < n; i++) {
                ptr = q.front();
                q.pop();
                sum += ptr->val;
                if(ptr->left != NULL) {
                    q.push(ptr->left);
                    count++;
                }
                if(ptr->right != NULL) {
                    q.push(ptr->right);
                    count++;
                }
            }
            v.push_back((double)sum / n);
            n = count;
            count = 0;
            sum = 0;
        }
        
        return v;
    }
};
