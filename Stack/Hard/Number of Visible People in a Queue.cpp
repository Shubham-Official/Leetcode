//Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
//Similar to Next Greater Element

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> see, ans(n, 0);
        
        for(int i=n-1; i>=0; --i){
            while(!see.empty() and see.back() < heights[i]){
                ans[i]++;
                see.pop_back();
            }
            if(!see.empty()) ans[i]++;
            see.push_back(heights[i]);
        }
        
        return ans;
    }
};