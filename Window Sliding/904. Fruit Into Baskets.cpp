// Problem Link : https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp; // to store frequency in the window.
        int ans = 0;
        int i = 0, j = 0;
        
        while(j < fruits.size()){
            mp[fruits[j++]]++; // add new element into map
            
            // remove from map while window is not valid
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }
            ans = max(ans,j-i); // update answer
        }
        return ans;
    }
};
