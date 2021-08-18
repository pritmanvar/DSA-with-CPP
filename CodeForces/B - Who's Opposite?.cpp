// Problem Link : https://codeforces.com/contest/1560/problem/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int a,b,c;
        cin >> a >> b >> c;

        int n = abs(a-b);

        if(a > 2*n || b > 2*n || c > 2*n){
            cout << -1 << endl;
        }else if(c <= n){
            cout << c+n << endl;
        }else{
            cout << c-n << endl;
        }
    }
    return 0;
}
