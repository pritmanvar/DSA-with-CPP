class Solution {
private:
// Problem Link : https://leetcode.com/problems/house-robber/
/*
    // TOP DOWN approch.
    
    // willBreak -> I have to break current house or not.
    int solve(vector<int>& nums, bool willBreak, int indx, vector<vector<int>>& dp){
        if(indx < 0) // if there are no houses
            return 0;
        
        if(dp[indx][willBreak] != -1){ // answer of this case is already present.
            return dp[indx][willBreak];
        }
        
        if(willBreak){
            // i am robbing in this house so i can't break next house.
            return dp[indx][1] = nums[indx] + solve(nums,false,indx-1,dp);
        }else{
            // i am not robbing in this house so i have 2 posibilities for next house.
            int amount1 = solve(nums,true,indx-1,dp);
            int amount2 = solve(nums,false,indx-1,dp);
            return dp[indx][0] = max(amount1,amount2); // store answer into dp
        }
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return max(solve(nums,true,n-1,dp),solve(nums,false,n-1,dp));
    }
*/
public:
    // BOTTOM UP approch.
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // in (i,0) cell it will store max amount if there is 'i' houses and i am not breaking 'i'th house
        // in (i,1) cell it will store max amount if there is 'i' houses and i am breaking 'i'th house
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        dp[0][0] = dp[0][1] = 0; // if there are no houses then max amount will be 0.
        
        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]); // there are 2 posibilities for next house if i am not breaking this.
            dp[i][1] = nums[i-1] + dp[i-1][0];
        }
        return max(dp[n][0],dp[n][1]);
    }
};
