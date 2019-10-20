#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    struct ListNode
    {
        int key, val;
        struct ListNode *next, *prev;
        ListNode(int _key, int _val) : key(_key), val(_val) {}
    };
    ListNode *head, *tail;
    int caplimit;
    unordered_map<int, ListNode *> M;

    // O(1)
    void remove(ListNode *node)
    {
        if (node == head)
            head = node->next;
        if (node == tail)
            tail = tail->prev;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
    }

    // O(1)
    void tail_insert(ListNode *node)
    {
        node->next = nullptr;
        if (!head)
        {
            head = tail = node;
            node->prev = nullptr;
        }
        else
        {
            tail->next = node, node->prev = tail, tail = node;
        }
        M[node->key] = node;
    }

    LRUCache(int capacity)
    {
        caplimit = capacity;
        head = tail = nullptr;
    }

    // O(1)
    int get(int key)
    {
        if (M.find(key) == M.end())
            return -1;
        else
        {
            remove(M[key]);
            tail_insert(M[key]);
            return M[key]->val;
        }
    }

    // O(1)
    void put(int key, int value)
    {
        ListNode *tnode;
        if (M.find(key) != M.end())
            tnode = M[key], tnode->val = value, remove(M[key]);
        else if (M.size() == caplimit)
            tnode = head, M.erase(tnode->key), tnode->key = key, tnode->val = value, remove(head);
        else
            tnode = new ListNode(key, value);
        tail_insert(tnode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */