// Problem Link : https://codeforces.com/problemset/problem/546/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n,w;
    cin >> k >> n >> w;
    int ans = n - k*(w*(w+1)/2);
    if(ans < 0)
        cout << -ans << endl;
    else
        cout << 0 << endl;
    return 0;
}
