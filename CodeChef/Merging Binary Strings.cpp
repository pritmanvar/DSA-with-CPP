// Problem Link : https://www.codechef.com/START22B/problems/MERGEBS
// Problem of DP

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(string& first, string& second, int f, int s, int zeros, vector<vector<int>>& dp){
    if(f < -1 || s < -1)
        return INT_MAX;
    if(f == -1 && s == -1)
        return 0;

    if(dp[f+1][s+1] != -1){
        return dp[f+1][s+1];
    }
    if(f >= 0 && first[f] == '1'){
        return dp[f+1][s+1] = solve(first,second,f-1,s,zeros,dp)+zeros;
    }else if(s >= 0 && second[s] == '1'){
        return dp[f+1][s+1] = solve(first,second,f,s-1,zeros,dp)+zeros;
    }else{
        int ans1,ans2;
        ans1 = solve(first,second,f-1,s,zeros+1,dp);
        ans2 = solve(first,second,f,s-1,zeros+1,dp);

        return dp[f+1][s+1] = min(ans1,ans2);
    }
}
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        string first,second;
        cin >> first >> second;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        cout << solve(first,second,n-1,n-1,0,dp) << endl;
    }
    return 0;
}
