//Link: https://leetcode.com/problems/maximum-binary-tree/

Approach 1: Using stack

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> v;
        
        for(auto n: nums){
            TreeNode* node = new TreeNode(n);
            
            while(!v.empty() and n > v.back()->val){
                node->left = v.back();
                v.pop_back();
            }
            
            if(!v.empty()){
                v.back()->right = node;
            }
            
            v.push_back(node);
        }
        
        return v[0];
    }
};

Approach 2: Recursion

class Solution {
public:
    TreeNode* helper(vector<int> nums, int left, int right){
        if(left > right) return NULL;
        
        int maxe = INT_MIN;
        int idx = 0;
        
        for(int i=left; i<=right; ++i){
            if(nums[i] > maxe){
                maxe = nums[i];
                idx = i;
            }
        }
        
        TreeNode* node = new TreeNode(maxe);
        
        node->left = helper(nums, left, idx-1);
        node->right = helper(nums, idx+1, right);
        
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};