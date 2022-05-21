// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix_sum; // to store prefix sum and it's frequency
        prefix_sum[0] = 1; // for empty array
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans += prefix_sum[sum - k];
            prefix_sum[sum]++;
        }
        return ans;
    }
};
