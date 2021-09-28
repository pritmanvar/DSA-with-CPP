// Problem Link : https://codeforces.com/contest/1579/problem/C

#include<bits/stdc++.h>

#define long long int ll
using namespace std;

void fill(vector<vector<char>>& ans, vector<vector<char>>& arr, int k, int r, int c, int n, int m){
    bool check = true;
    for(int i = 0; i < k; i++){
        if(arr[r-i-1][c-i-1] == '.' || arr[r-i-1][c+i+1] == '.'){
            check = false;
            break;
        }
    }
    if(check == true){
        ans[r][c] = '*';
        int i = 0;
        while(r-i-1 >= 0 && c-i-1 >= 0 && c+i+1 <= m && arr[r-i-1][c-i-1]=='*' && arr[r-i-1][c+i+1] == '*'){
            ans[r-i-1][c-i-1] = ans[r-i-1][c+i+1] = '*';
            i++;
        }
    }
}
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,m,k;
        cin >> n >> m >> k;

        vector<vector<char>> ans(n,vector<char>(m,'.'));
        vector<vector<char>> arr(n,vector<char>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == '*' && i >= k && j >= k && m-j-1 >= k){
                    fill(ans,arr,k, i, j, n, m);
                }
            }
        }
        bool check = true;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] != ans[i][j]){
                    check = false;
                    break;
                }
                if(check == false)
                    break;
            }
        }
        if(check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
