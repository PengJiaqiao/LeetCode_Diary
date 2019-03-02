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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false;
        return compare(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool compare(TreeNode* s, TreeNode* t) {
        if (s==NULL && t == NULL) return true;
        else if (s!=NULL && t!=NULL) {
            if (s->val != t->val) return false;
            else return compare(s->left, t->left) && compare(s->right, t->right);
        }
        else return false;
    }
};
