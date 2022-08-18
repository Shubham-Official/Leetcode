//Link: https://leetcode.com/problems/count-sorted-vowel-strings/

Approach 1: Recursion

class Solution {
public:
    int cnt = 0;
    
    void helper(int n, int idx, int currcnt){
        currcnt++;
        
        if(currcnt == n){
            cnt++;
            return;
        }
        
        for(int i = idx; i<5; ++i){
            helper(n, i, currcnt);
        }
        
        return;
    }
    
    int countVowelStrings(int n) {

        for(int i=0; i<5; ++i){
            helper(n, i, 0);
        }
            
        return cnt; 
    }
};

Approach 2: Recursion with dp

const int nx = 55;
long dp[nx][6];

class Solution {
public:
    int n;
    long func(int ind, int prev) {
        if(ind >= n) return 1;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        long ans = 0;
        for(int i = prev; i < 5; ++i) {
            ans += func(ind + 1, i);
        }
        
        return dp[ind][prev] = ans;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        
        return func(0, 0);
    }
};

Approach 3: iterative dp

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(6));
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
        return dp[n][5];
    }
};