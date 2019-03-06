class MapSum {
private:
    struct TrieNode {
        int val = 0;
        TrieNode *next[52] = {NULL};
    };
	TrieNode trie;
    int Ascii2Num(char key) {
        if(key < 90) return key - 65;
        else return key - 71;
    }
    int sum(TrieNode* root) {
        if(!root || !root->next) return 0;
        int s = root->val;
        for(auto& ptr : root->next) {
            s += sum(ptr);
        }
        return s;
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        TrieNode* ptr = &trie;
		for(auto &v : key) {
			if (!ptr->next[Ascii2Num(v)]) ptr = ptr->next[Ascii2Num(v)] = new TrieNode();
			else ptr = ptr->next[Ascii2Num(v)];
		}
        ptr->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* ptr = &trie;
		for(auto &v : prefix) {
			if (!ptr->next[Ascii2Num(v)]) return NULL;
			else ptr = ptr->next[Ascii2Num(v)];
		}
		return sum(ptr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
