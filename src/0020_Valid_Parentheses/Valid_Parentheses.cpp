class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() % 2 == 1) return false;
        stack<char> stack;
        unordered_map<char, char> M = {{'(',')'}, {'{','}'}, {'[',']'}};
        for(char i : s) {
            if(i == '(' || i == '{' || i == '[') stack.push(i);
            else {
                if(stack.empty()) return false;
                if(M[stack.top()] != i) return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
