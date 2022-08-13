//Link: https://leetcode.com/problems/remove-k-digits/

class Solution{
public:
    string removeKdigits(string num, int k) {
        vector<char> v;
        string ans = "";
        
        for(auto c: num){
            if(v.empty() and c != '0'){
                v.push_back(c);  
            }else if(!v.empty() and c >= v.back()){
                v.push_back(c);
            }else{
                while(!v.empty() and k and c< v.back()){
                    v.pop_back();
                    k--;
                }
                if(v.empty() and c == '0'){
                    continue;
                }
                v.push_back(c);
            }
        }
        
        while(!v.empty() and k){
            v.pop_back();
            k--;
        }
        
        for(auto c: v){
            ans += c;
        }
        
        if(ans == "") ans = "0";
        
        return ans;
    }
};