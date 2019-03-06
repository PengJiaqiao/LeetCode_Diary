class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(findNums.size() == 0) return {};
        stack<int> s;
        vector<int> v;
        unordered_map<int, int> M;
        for(int i : nums) {
            while (!s.empty() && i > s.top())
            {
                M[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for(int i : findNums) {
            if(M.find(i) != M.end()) v.push_back(M[i]);
            else v.push_back(-1);
        }
        return v;
    }
};
