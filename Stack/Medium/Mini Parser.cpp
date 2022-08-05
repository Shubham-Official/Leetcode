//Link: https://leetcode.com/problems/mini-parser/
//Given NestedInteger class should be used

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '[') return NestedInteger(stoi(s));
        
        vector<NestedInteger> v;
        string num = "";
        
        for(auto c: s){
            if(c == '['){
                v.push_back(NestedInteger());
            }
            else if(c == ']' or c == ','){
                if(num != ""){
                    v.back().add(NestedInteger(stoi(num)));
                    num = "";
                }
                
                if(c == ']' and v.size() >= 2){
                    NestedInteger ni = v.back();
                    v.pop_back();
                    v.back().add(ni);
                }
            }
            else num.push_back(c);
        }
        
        return v.back();
    }
};