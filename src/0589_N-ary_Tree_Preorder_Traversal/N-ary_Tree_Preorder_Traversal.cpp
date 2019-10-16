#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }

private:
    void dfs(Node *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
            dfs(root->children[i], res);
        return;
    }
};