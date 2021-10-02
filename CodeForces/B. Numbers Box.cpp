// Problem Link : https://codeforces.com/problemset/problem/1447/B

#include<bits/stdc++.h>

using namespace std;

// If number of negative elements is even then it will be possible to make all element positive
// but it this number is odd then there is a single number which will be negarive in this case i will make number negarive which absolute value is smalles to get maximum sum.
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> grid(n,vector<int>(m));
        int negative = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] < 0){
                    negative++;
                }
                mn = min(mn,abs(grid[i][j]));
            }
        }
        int ans = 0;
        bool set = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(negative%2 == 0){
                    ans += abs(grid[i][j]);
                }else{
                    if(abs(grid[i][j]) == mn && set == false){
                        ans -= abs(mn);
                        set = true;
                    }else{
                        ans += abs(grid[i][j]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
   return 0;
}
