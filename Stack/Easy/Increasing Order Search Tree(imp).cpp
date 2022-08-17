//Link: https://leetcode.com/problems/increasing-order-search-tree/

Approach 1: Recursion

class Solution {
public:   
    TreeNode* increasingBST(TreeNode* root, TreeNode* next = NULL) {
        if(root == NULL) return next;
        root->right = increasingBST(root->right, next);
        TreeNode* temp = increasingBST(root->left, root);
        root->left = NULL;
        return temp;
    }
};

Approach 2: Iterative

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        TreeNode* newcurr = nullptr, *head = nullptr, *curr = root;
        
        while(curr || !v.empty()){
            while(curr){
                v.push_back(curr);
                curr = curr->left;
            }
            
            curr = v.back();
            v.pop_back();
            
            if(!newcurr){
                head = new TreeNode(curr->val);
                newcurr = head;
            } else {
                newcurr->right = new TreeNode(curr->val);
                newcurr = newcurr->right;
            }
            
            curr = curr->right;
        }
        
        
        
       return head; 
    }
};