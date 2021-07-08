// Problem Link : https://codeforces.com/contest/1543/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        long long int a,b;
        cin >> a >> b;
 
        if(a == b){
            cout << 0 << " " << 0 << endl;
        }else{
            long long int mx = abs(a-b);
            long long int mn = min(a-a/mx*mx,a/mx*mx+mx-a);
            
            cout << mx << " " << mn << endl;
        }
    }
    return 0;
}
