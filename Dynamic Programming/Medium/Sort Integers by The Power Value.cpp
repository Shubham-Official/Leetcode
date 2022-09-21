//Link: https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
public:
    int dp[3001];
    
    int helper(int idx){
        
        int cnt = 0;
        int num = idx;
        
        while(num != 1){
            
            if(idx < 3001 and dp[idx] != -1){
                return dp[idx] = cnt + dp[idx];
            }
            if(num % 2 == 0){
                num /= 2;
            } else {
                num = num * 3 + 1;
            }
            
            cnt++;
        }
        
        return dp[num] = cnt;
        
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        
        memset(dp, -1, sizeof dp);
        
        for(int i = lo; i <= hi; ++i){
            v.push_back({helper(i), i});  
        }
        
        sort(v.begin(), v.end());
        
        return v[k-1].second;
    }
}; 