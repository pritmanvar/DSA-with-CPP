// Problem Link : https://codeforces.com/problemset/problem/1537/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;

    // To get maximum distance Riley will throw both yoyos at the pair of opposit corners.
    // not Riley will select that pair which contains a corner with maximum distance from Anton's position,.
    for (int z = 1; z <= t; z++){
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        // distance between various corner and Anton's position.
        int c1 = r-1+c-1;
        int c2 = r-1+m-c;
        int c3 = n-r+c-1;
        int c4 = n-r+m-c;

        int mx = max(max(c1,c2),max(c3,c4));

        if(mx == c1 || mx == c4){
            cout << 1 << " " << 1 << " " << n << " " << m << endl;
        }else{
            cout << 1 << " " << m << " " << n << " " << 1 << endl;
        }
    }
    return 0;
}
