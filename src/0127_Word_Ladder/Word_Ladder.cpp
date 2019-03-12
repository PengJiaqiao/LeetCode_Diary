class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int idx;//which word in the list is equal to endword
        for(idx = 0; idx < wordList.size(); idx++) {
            if(endWord == wordList[idx]) break;
        }
        if(idx == wordList.size()) return 0;

        vector<int> v_begin;//the index of word in the list which can be changed from begin word directly
        for(int i = 0; i < wordList.size(); i++) {
            if(canChange(beginWord, wordList[i])) v_begin.push_back(i);
        }
        //the index of word in the list which can be changed from other word in the list directly
        vector<vector<int>> v_list(wordList.size());
        for(int i = 0; i < wordList.size() - 1; i++) {
            for(int j = i + 1; j < wordList.size(); j++) {
                if(canChange(wordList[i], wordList[j])) {
                    v_list[i].push_back(j);
                    v_list[j].push_back(i);
                }
            }
        }
        
        unordered_set<int> set;
        for(int num : v_begin) set.insert(num);
        if(set.find(idx) != set.end()) return 2;
        for(int count = 0; count < wordList.size(); count++) {
            unordered_set<int> tmp;
            for(auto num : set) {
                for(auto next : v_list[num]) tmp.insert(next);
            }
            if(tmp.find(idx) != tmp.end()) return count + 3;
            swap(set, tmp);
        }
        return 0;
    }
private:
    bool canChange(string& word1, string& word2) {
        int count = 0;
        for(int i = 0; i < word1.size(); i++) {
            if(word1[i] != word2[i]) count++;
        }
        return count == 1;
    }
};
