// Problem Link : https://codeforces.com/problemset/problem/912/B

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin >> n >> k;

    if(k == 1)
        cout << n << endl;
    else{
        ll ans = powl(2,(ll)log2(n)) - 1;
        if(ans == n){
            cout << ans << endl;
        }else{
            cout << (ans + 1)*2 - 1 << endl;
        }
    }

    return 0;
}
