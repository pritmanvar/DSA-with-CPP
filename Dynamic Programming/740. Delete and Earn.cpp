// Problem Link : https://leetcode.com/problems/delete-and-earn/

class Solution {
    
// TOP DOWN Approch
/* private:
    int solve(vector<pair<int,int>>& arr, int n, vector<int>& dp){
        if(n < 0) // if there is no number then i can't delete anything.
            return 0;
        
        if(dp[n] != -1) // answer for this case is already calculated
            return dp[n];
        
        if(n > 0 && arr[n].first-1 == arr[n-1].first){ // it is condition that if i delete current number then i have to delete next number. 
            
            // here i have 2 cases
            // case 1 : i don't delete current number
            // case 2 : i delete both number and add earning 
            int earn1 = solve(arr,n-1,dp);
            int earn2 = arr[n].second + solve(arr,n-2,dp);
            
            return dp[n] = max(earn1,earn2);
        }else{
            return dp[n] = arr[n].second + solve(arr,n-1,dp); // safe case because arr[i-1] != arr[i]-1
        }
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        int sizeArr = 0;
        
        // if i am deleting number 'k' then i can surly delete all iteration of number 'k' so merging them all.
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                arr[sizeArr-1].second += nums[i];
            }else{
                arr.push_back({nums[i],nums[i]});
                sizeArr++;
            }
        }
        
        vector<int> dp(sizeArr,-1);
        return solve(arr,sizeArr-1,dp);
    }
*/

// BOTTOM UP approch.
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        int sizeArr = 0;
        
        // if i am deleting number 'k' then i can surly delete all iteration of number 'k' so merging them all.
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                arr[sizeArr-1].second += nums[i];
            }else{
                arr.push_back({nums[i],nums[i]});
                sizeArr++;
            }
        }
        
        vector<int> dp(sizeArr+1,-1);
        dp[0] = 0;
        for(int i = 1; i <= sizeArr; i++){ // top down to bottom up conversion
            if(i > 1 && arr[i-1].first-1 == arr[i-2].first){
                dp[i] = max(dp[i-1],arr[i-1].second + dp[i-2]);
            }else{
                dp[i] = arr[i-1].second + dp[i-1];
            }
        }
        return dp[sizeArr];
    }
};
