// Problem Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freqOfReminder(k);
        
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            int rem;
            if(sum < 0)
                rem = (k - abs(sum)%k)%k;
            else
                rem = sum%k;
            
            ans += freqOfReminder[rem];
            freqOfReminder[rem]++;
            if(rem == 0)
                ans++;
        }
        return ans;
    }
};
