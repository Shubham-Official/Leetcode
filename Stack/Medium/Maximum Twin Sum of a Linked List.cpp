//Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
    int tsum = 0;
    ListNode* temp = NULL;
    
    void helper(ListNode* node){
        if(node == NULL) return;
        
        helper(node->next);
    
        tsum = max(temp->val + node->val, tsum);
        temp = temp->next;
    }
    
    int pairSum(ListNode* head) {
        
        temp = head;
        helper(head);
        return tsum;
    }
};