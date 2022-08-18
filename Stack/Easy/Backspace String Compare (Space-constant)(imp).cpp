//Link: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int j = 0, k = 0, ns = s.size(), nt = t.size();
        
        for(int i = 0; i < ns; ++i, j++){
            s[j] = s[i];
            
            if(j == 0 and s[j] == '#') j = -1;
            else if(j > 0 and s[j] == '#') j -= 2;
        }
        
        for(int i = 0; i < nt; ++i, k++){
            t[k] = t[i];
            
            if(k == 0 and t[k] == '#') k = -1;
            else if(k > 0 and t[k] == '#') k -= 2;
        }
        
        if(k < 0 and j < 0) return true;
        
        else return s.substr(0, j) == t.substr(0, k);
    }
};

Time: O(N), Space: O(1).