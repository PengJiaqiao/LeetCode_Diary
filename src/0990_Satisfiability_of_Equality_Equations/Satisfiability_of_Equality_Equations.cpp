class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<int> ds(26); //Disjoint-set
        vector<pair<int, int>> notequal;
        for(int i = 0; i < 26; i++) ds[i] = i;
        for(string equation : equations) {
            if(equation[1] == '=') {
                if(equation[0] == equation[3]) continue;
                else {
                    int a = equation[0] - 'a';
                    int b = equation[3] - 'a';
                    int father_a = find(a, ds);
                    int father_b = find(b, ds);
                    if(father_a == father_b) continue;
                    else ds[father_a] = father_b;
                }
            }
            else {
                if(equation[0] == equation[3]) return false;
                else {
                    pair<int, int> tmp;
                    tmp.first = equation[0] - 'a';
                    tmp.second = equation[3] - 'a';
                    notequal.push_back(tmp);
                }
            }
        }
        for(auto& pair : notequal) {
            if(find(pair.first, ds) == find(pair.second, ds)) return false;
        }
        return true;
    }
private:
    int find(int x, vector<int>& father) { //find root
        if(father[x] == x) return x; 
        return find(father[x], father);
    }
};
