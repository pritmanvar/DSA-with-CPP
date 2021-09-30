// Problem Link : https://codeforces.com/problemset/problem/523/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int m,n;
    cin >> m >> n;

    vector<vector<char>> rotation(2*m, vector<char>(2*n));
    // with this pattern of input i will rotate the grid.
    // but it will be reversed order in every row.
    for(int i = 2*(n-1); i >= 0; i -= 2){
        for(int j = 2*(m-1); j >= 0; j -= 2){
            cin >> rotation[j][i];
            rotation[j+1][i] = rotation[j][i+1] = rotation[j+1][i+1] = rotation[j][i]; // this line will be zoom the grid.
        }
    }
  
    reverse(rotation.begin(),rotation.end()); // to flip the grid.
    
    // this line will reversed the every row.
    // we need this step because we got reversed order of every row while rotation of grid.
    for(int i = 0; i < 2*m; i++){
        reverse(rotation[i].begin(),rotation[i].end());
    }
    for(int i = 0; i < 2*m; i++){
        for(int j = 0; j < 2*n; j++){
            cout << rotation[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
