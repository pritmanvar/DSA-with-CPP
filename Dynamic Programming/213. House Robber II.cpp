// Problem Link : https://leetcode.com/problems/house-robber-ii/

// Hint : Since House[1] and House[n] are adjacent, they cannot be robbed together. 
// Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. 
// Now the problem has degenerated to the House Robber, which is already been solved.
// Link for House Robber : https://github.com/pritmanvar/DSA-with-CPP/blob/main/Dynamic%20Programming/198.%20House%20Robber.cpp
class Solution {
public:
    // BOTTOM UP approch.
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        // in (i,0) cell it will store max amount if there is 'i' houses and i am not breaking 'i'th house
        // in (i,1) cell it will store max amount if there is 'i' houses and i am breaking 'i'th house
        vector<vector<int>> dp1(n,vector<int>(2,-1));
        vector<vector<int>> dp2(n+1,vector<int>(2,-1));
        
        dp1[0][0] = dp1[0][1] = 0; // if there are no houses then max amount will be 0.
        dp2[1][0] = dp2[0][1] = 0;
        
        for(int i = 1; i < n; i++){
            dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1]); // there are 2 posibilities for next house if i am not breaking this.
            dp1[i][1] = nums[i-1] + dp1[i-1][0];
            
            dp2[i+1][1] = nums[i] + dp2[i][0];
            dp2[i+1][0] = max(dp2[i][0],dp2[i][1]);
        }
        
        return max(max(dp2[n][0],dp2[n][1]),max(dp1[n-1][0],dp1[n-1][1]));
    }
};
