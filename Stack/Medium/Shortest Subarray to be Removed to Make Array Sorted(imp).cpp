// Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
// Approach Using two pointers.

class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
	    int n = arr.size(), r = n-1;
	    
		//below loop will calculate the non-decreasing sub-array from right and r points to the first element of that sub-array.
	    while(r > 0 and arr[r-1] <= arr[r]) --r;
	    
	    int ans = r;
	    
		//Now using two-pointers, we will calculate the min length of sub-array to be deleted.
		//we will check two conditions:
		//1.element pointed by i should be in non-decresing order i.e. arr[i-1] <= arr[i].
		//2.element at right(pointed by r) should be greater than element at left(pointed by i), if not than we will increment r and again check.
	    for(int i=0; i < r and (i == 0 or arr[i-1] <= arr[i]); ++i){
	        while(r < n and arr[r] < arr[i]) ++r;
	        
	        ans = min(ans, r-i-1);// consider the minimum length of subarray.
	    }
	    return ans;
	}
};