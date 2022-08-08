//Link: https://leetcode.com/problems/valid-parenthesis-string/
//Refer: https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis

Approach 1: Time:O(N), Space: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }
};

Approach 2: Time: O(N), Space: O(N)

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open, ast;
        int flag = 0;
        
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '('){
                open.push_back(i);
            } else if(s[i] == '*'){
                ast.push_back(i);
            } else {
                if(!open.empty()) open.pop_back();
                else if(!ast.empty()){
                    ast.pop_back();
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        
        while(!open.empty() and !ast.empty()){
            if(open.back() < ast.back()){
                open.pop_back();
                ast.pop_back();
            } else {
                break;
            }
        }
        
        return flag == 1 ? false : open.empty();
    }
};

