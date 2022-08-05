//Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//Find first non sorted position from both the ends and diff is ans.

Approach 1: Time: O(N), Space: O(N);

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int r = 0, l = n-1;
        
        for(int i=0; i<n; ++i){            
            while(!v.empty() and nums[v.back()] > nums[i]){
                l = v.back() < l ? v.back() : l;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        v.clear();
        
        for(int i=n-1; i>=0; --i){
            while(!v.empty() and nums[i] > nums[v.back()]){
                r = v.back() > r ? v.back() : r;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        if(r == 0 and l == n-1) return 0;
        else return r - l + 1;
    }
};

Approach 2: Time: O(N), Space: O(1);

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	int n = nums.size();
        int end = -1;
        int max = nums[0];
        
        for(int i = 1; i < n; i++){
            if(max > nums[i]){ // the left value is greater then current value
                end = i; // mark that index with end
            }
            else{
                max = nums[i];
            }
        }
        
        int start = 0;
        int min = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(min < nums[i]){ // the right value is smaller then current value
                start = i; // mark that index with start
            }
            else{
                min = nums[i];
            }
        }
        return end - start + 1;
    }
};