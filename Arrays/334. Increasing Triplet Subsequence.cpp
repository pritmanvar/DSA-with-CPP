// Problem Link : https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        priority_queue<int> small; // it will store elements in the left of current
        priority_queue<int,vector<int>,greater<int>> large; // it will store elements in the right of current
        vector<pair<bool,bool>> small_large(nums.size());
        
        for(int i = nums.size()-1; i >= 0; i--){
            // if there is a smaller element on the left
            if(small.size() > 0 && small.top() > nums[i])
                small_large[i].second = true;
            small.push(nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++){
            // if there is a larger element on the right
            if(large.size() > 0 && large.top() < nums[i])
                small_large[i].first = true;
            large.push(nums[i]);
            
            // if left side has atleast one smaller and right side has atleast one larger element
            if(small_large[i].first == true && small_large[i].second == true)
                return true;
        }
        return false;
    }
};
