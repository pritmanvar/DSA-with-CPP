// Problem Link : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0; // to store answer
        map<int,int> mp; // to get max and min number of window
        int i = 0, j = 0;
        
        // if max-min <= limit then it is valid window
        while(j < nums.size()){
            // I am considiring windo from i to j-1
            if(mp.empty() || (*mp.rbegin()).first - (*mp.begin()).first <= limit){ // window is valid
                ans = max(ans,j-i); // update answer
                
                // insert j into map for next iteration
                mp[nums[j]]++;
                j++;
            }else{ // Invalid window so i will remove 1st element of window.
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
        }
        // I haven't consider last num so considiring that here
        if((*mp.rbegin()).first - (*mp.begin()).first <= limit)
            ans = max(ans,j-i);
        return ans;
    }
};
