Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

Approach 1: Greedy

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int weak_char = 0, max_attack = 0;
        
        for(auto &p: properties){
            int attack = p[0];
            max_attack = max(max_attack, attack);
        }
        
        vector<int> max_def(max_attack+2, 0);
        
        for(auto &p: properties){
            max_def[p[0]] = max(max_def[p[0]], p[1]);
        }
        
        for(int i=max_attack-1; i>=0; --i){
            max_def[i] = max(max_def[i], max_def[i+1]);
        }
        
        for(auto &p: properties){
            if(p[1] < max_def[p[0]+1]) weak_char++;
        }
        
        return weak_char;
    }
};

Approach 2: Using Sort

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int mx = 0, cnt = 0;
        
        for(auto &p: properties){
            if(p[1] < mx) cnt++;
            mx = max(mx, p[1]);
        }
        
        return cnt;
    }
};