class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        bool l, r;
        while(i < j) {
            l = isVowels(s[i]);
            r = isVowels(s[j]);
            if(l && r) swap(s[i], s[j]);
            else if(l) i--;
            else if(r) j++;
            i++;
            j--;
        }
        return s;
    }
private:
    bool isVowels(char letter) {
        switch(letter) {
            case 'a': return true;
            case 'A': return true;
            case 'e': return true;
            case 'E': return true;
            case 'i': return true;
            case 'I': return true;
            case 'o': return true;
            case 'O': return true;
            case 'u': return true;
            case 'U': return true;
            default: return false;
        }
    }
    void swap(char& letter1, char& letter2) {
        char tmp = letter2;
        letter2 = letter1;
        letter1 = tmp;
        return;
    }
};
