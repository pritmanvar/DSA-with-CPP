// Problem Link : https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[n-1] = true;
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j <= nums[i]; j++){
                if(dp[i+j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
