class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> v(T.size());
        stack<int> s;//index
        s.push(0);
        for(int i = 1; i < T.size(); i++) {
            while(!s.empty() && T[i] > T[s.top()]) {
                v[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
};
