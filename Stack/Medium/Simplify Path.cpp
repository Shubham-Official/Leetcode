//Link: https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        string curr = "", ans = "/";
        int n = path.size();
        
        //if path is not ending with '/' it will add '/' at the end. exp case: "/a//b////c/d//././/.."
        if(path[n-1] != '/') path += '/';
        
        for(int i=1; i<=n; ++i){
            int a = ans.size();
            
            if(path[i] == '/' and ans[a-1] == '/' and curr.empty()) continue;
            
            if(path[i] == '/'){
                if(curr == ".."){
                    if(a == 1){
                        curr = "";
                    } else {
                        ans.pop_back();
                        while(ans.back() != '/'){
                            ans.pop_back();
                        }
                        curr = "";
                    }
                } else if(curr == "."){
                    curr = "";
                } else {
                    ans += curr;
                    curr = "";
                    ans += "/";
                }
            } else {
                curr += path[i];
            } 
        }
            
        
        if(ans.size() != 1) ans.pop_back();
        return ans;
    }
};