class Trie {
private:
    struct TrieNode {
        bool valid = false;
        TrieNode *next[26] = { nullptr };
    };
	TrieNode trie;
    
public:
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* ptr = &trie;
		for (auto &v : word) {
			if (!ptr->next[v - 'a']) ptr = ptr->next[v - 'a'] = new TrieNode();
			else ptr = ptr->next[v - 'a'];
		}
		ptr->valid = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* ptr = &trie;
		for (auto &v : word) {
			if (!ptr->next[v - 'a']) return false;
			else ptr = ptr->next[v - 'a'];
		}
		return ptr->valid;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* ptr = &trie;
		for (auto &v : prefix) {
			if (!ptr->next[v - 'a']) return false;
			else ptr = ptr->next[v - 'a'];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
