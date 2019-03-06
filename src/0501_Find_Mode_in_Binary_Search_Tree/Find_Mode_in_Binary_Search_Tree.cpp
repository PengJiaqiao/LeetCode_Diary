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
    vector<int> v = {};
    int cur;//for comparion
    int max;//how many time the privious most frequent number appears
    int count = 0;//for current
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return v;
        dfs(root);
        if(count < max) v.pop_back();
        else if (count > max) {
            max = count;
            v.erase(v.begin(), v.end() - 1);
        }
        return v;
    }
private:
    void dfs(TreeNode* root) {
        if(root == NULL) return;
        dfs(root->left);
        if(v.empty()) {
            v.push_back(root->val);
            cur = root->val;
            count = 1;
            max = 1;
        }
        else {
            if(root->val != cur) {
                if(count < max) v.pop_back();
                else if (count > max) {
                    max = count;
                    v.erase(v.begin(), v.end() - 1);
                }
                cur = root->val;
                v.push_back(root->val);
                count = 1;
            }
            else count++;
        }  
        dfs(root->right);
        return;        
    }
};
