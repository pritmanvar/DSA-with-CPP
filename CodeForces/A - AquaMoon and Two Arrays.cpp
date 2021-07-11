// Problem Link : https://codeforces.com/contest/1546/problem/A

#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        vector<vector<pair<int,int>>> diff(2);
 
        int sum1  = 0;
        int sum2 = 0;
        int mooves = 0;
 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum1 += a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            sum2 += b[i];
 
            if(a[i] > b[i]){
                diff[0].push_back({i,a[i]-b[i]});
                mooves += a[i]-b[i];
            }else if(a[i] < b[i]){
                diff[1].push_back({i,b[i]-a[i]});
            }
        }
 
        if(sum1 != sum2){
            cout << -1 << endl;
            continue;
        }
 
        cout << mooves << endl;
        while(diff[0].size() !=0){
            cout << diff[0][0].first+1 << " " << diff[1][0].first+1 << endl;
            diff[0][0].second--;
            diff[1][0].second--;
            if(diff[0][0].second == 0){
                // cout << "hii ";
                diff[0].erase(diff[0].begin());
                // cout << diff[0].size() << " ";
            }
            if(diff[1][0].second == 0){
                diff[1].erase(diff[1].begin());
            }
        }
    }
    return 0;
}
