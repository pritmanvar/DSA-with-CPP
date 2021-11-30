// Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/
// Referance : https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235417/Sliding-Window-Logical-Thinking
//           : https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/672979/Analysis-and-explanation-with-Visualization

class Solution {
public:
    // To count number of subarray with at most K distinct numbers.
    int atMostK(vector<int>& nums, int k){
        int ans = 0;
        unordered_map<int,int> mp;
        int i = 0,j = 0;
        
        while(j < nums.size()){
            mp[nums[j]]++;
            if(mp.size() <= k){
                ans += j-i+1;
            }else{
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
                ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};
