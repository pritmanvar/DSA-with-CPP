// Problem Link : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

// Top-Down
class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2){
        if(v1[1] == v2[1])
            return v1[2] < v2[2];
        return v1[1] < v2[1];
    }
    int bsearch(vector<vector<int>>& events, int val, int high){
        int low = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(events[mid][1] < val){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return high+1;
    }
    int solve(vector<vector<int>>& events, vector<vector<int>>& dp, vector<int>& size, int n, int k){
        if(n == 0 || k == 0){
            return dp[n][k] = 0;
        }
        if(dp[n][k] == -1){
            dp[n][k] = solve(events,dp,size,n-1,k);
            dp[n][k] = max(dp[n][k],events[n-1][2] + solve(events,dp,size,size[n-1],k-1));
        }
        
        return dp[n][k];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),compare);
        vector<vector<int>> dp(events.size()+1, vector<int> (k+1,-1));
        
        vector<int> size(events.size()); // it will store max size of array if we want to attend ith 
        for(int i = 0; i < events.size(); i++){
            // fill size array with binary search
            // we will search for last event which ends before starting time of current one
            size[i] = bsearch(events,events[i][0],i);
        }
        
        solve(events,dp,size,events.size(),k); // call DP
        
        return dp[events.size()][k];
    }
};

// Bottom-Up
// Problem Link : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2){
        if(v1[1] == v2[1])
            return v1[2] < v2[2];
        return v1[1] < v2[1];
    }
    int bsearch(vector<vector<int>>& events, int val, int high){
        int low = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(events[mid][1] < val){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return high+1;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),compare);
        vector<vector<int>> dp(events.size()+1, vector<int> (k+1));
        
        vector<int> size(events.size()); // it will store max size of array if we want to attend ith event
        for(int i = 0; i < events.size(); i++){ 
            // fill size array with binary search
            // we will search for last event which ends before starting time of current one
            size[i] = bsearch(events,events[i][0],i);
        }
        
        for(int i = 1; i <= events.size(); i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = max(dp[i-1][j], events[i-1][2] + dp[size[i-1]][j-1]); // fill dp
            }
        }
        
        return dp[events.size()][k];
    }
};
