//Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, largestc = 0;
        int breadth = height.size()-1;
        
        while(left < right){
            
            int length = min(height[left], height[right]);
            int currentc = length * breadth;
            largestc = max(currentc, largestc);
            
            height[left] <= height[right] ? ++left : --right;
            
            breadth--;
        }
        
        return largestc;
    }
};