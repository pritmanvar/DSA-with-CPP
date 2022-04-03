// Problem Link : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        vector<pair<int,int>> dp(n+1);
        dp[0].first = 0;
        dp[0].second = 0;

        for(int i = 1; i <= n; i++){
            if(dp[i-1].second < arr[i-1] || dp[i-1].first < arr[i-1]){
                dp[i].first = dp[i-1].first+1;
                dp[i].second = min(dp[i-1].second+1,arr[i-1]);
            }else{
                dp[i] = dp[i-1];
            }
        }
        cout << "Case #" << z << ": " << dp[n].first << endl;
    }
    return 0;
}
