//Link: https://leetcode.com/problems/partition-array-for-maximum-sum/


//Approach 1
class Solution {
public:
    long dp[501];
    int n;
    
    long helper(vector<int> &arr, int k, int idx){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        long ans = 0, mx = 0;
        for(int i = idx; i < min(n, idx+k); ++i){
            mx = max(mx, 1L * arr[i]);
            ans = max(ans, (i - idx + 1) * mx + helper(arr, k, i + 1));
        }
        
        return dp[idx] = ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof dp);
        return helper(arr, k, 0);
    }
};


//Approach 2
const int nx = 550;
long dp[nx];

class Solution {
public:
    int k, n;
    vector<int> arr;
    
    long func(int ind) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long ans = 0, mx = 0;
        for(int i = ind; i < min(n, ind + k); ++i) {
            mx = max(mx, 1L * arr[i]);
            ans = max(ans, (i - ind + 1) * mx + func(i + 1));
        }
        
        return dp[ind] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k;    
        this->arr = arr;
        n = arr.size();
        
        memset(dp, -1, sizeof dp);
        
        return func(0);
    }
};