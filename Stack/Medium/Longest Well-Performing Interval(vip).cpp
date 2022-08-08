//Link: https://leetcode.com/problems/longest-well-performing-interval/

Approach 1: Using Stack

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        vector<int> pre(n+1, 0);
        for(int i=0; i<n; ++i) pre[i+1] = pre[i] + (hours[i] > 8 ? 1 : -1);

        vector<int> st;

        for(int i=0; i<=n; ++i){
            if(st.empty() or pre[st.back()] > pre[i]){
                st.push_back(i);
            }
        }

        int ans = 0;

        for(int i = n; i >= 0; --i){
            if(st.empty()) break;

            while(!st.empty() and pre[st.back()] < pre[i]){
                ans = max(ans, i - st.back());
                st.pop_back();
            }

            if(!st.empty() and st.back() == i) st.pop_back();
        }

        return ans;
    }
};

Approach 2: Using Unordered_map

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                res = i + 1;
            } else {
                if (seen.find(score) == seen.end())
                    seen[score] = i;
                if (seen.find(score - 1) != seen.end())
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
};
