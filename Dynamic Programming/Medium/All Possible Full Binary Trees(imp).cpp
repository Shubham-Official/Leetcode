//Link: https://leetcode.com/problems/all-possible-full-binary-trees/
//mhash is the custom implementation of hashing algorithm.(ignore it)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct mhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
class Solution {
public:
    unordered_map<int, vector<TreeNode*>, mhash> cache;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(cache[n].size() != 0) return cache[n];
        if(n == 1) return vector<TreeNode*> ({new TreeNode(0)});
        
        vector<TreeNode*> res;
        for(int i = 1; i < n; i += 2) {
            int lef = i, rig = n - i - 1;
            for(auto lchild: allPossibleFBT(lef)) {
                for(auto rchild: allPossibleFBT(rig)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = lchild;
                    root->right = rchild;
                    res.push_back(root);
                }
            }
        }
        
        return cache[n] = res;
    }
};