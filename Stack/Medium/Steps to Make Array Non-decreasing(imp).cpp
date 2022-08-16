//Link: https://leetcode.com/problems/steps-to-make-array-non-decreasing/

Approach 1:

//Explanation
//dp[i] means the number of element A[i] can eat on its right.
//More precisely, the number of rounds for an element A[i],
//to completely eat whatever it can eat on the right of A[i],
//if it is possible.

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> v, dp(n);

        for(int i = n-1; i >= 0; --i){
            while(!v.empty() and nums[i] > nums[v.back()]){
                dp[i] = max(++dp[i], dp[v.back()]);
                v.pop_back();
                ans = max(ans, dp[i]);
            }
            v.push_back(i);
        }

        return ans;
    }
};

Approach 2:

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<array<int, 2>> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int cnt = 0;
            while (!st.empty() && st.back()[1] < nums[i]) {
                cnt = max(cnt + 1, st.back()[0]);
                st.pop_back();
            }
            st.push_back({cnt, nums[i]});
        }
        return (*max_element(begin(st), end(st)))[0];
    }
};
