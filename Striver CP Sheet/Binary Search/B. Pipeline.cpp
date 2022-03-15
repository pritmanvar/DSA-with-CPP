// Problem Link : https://codeforces.com/contest/287/problem/B
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool isPossible(unsigned ll n, unsigned ll mid, unsigned ll k){
    // corner cases
    if(mid == 1){
        return n <= k;
    }else if(mid == k){ 
        return k*(k-1)/2 + 1 >= n;
    }
    mid--;

    unsigned ll possible = k*(k-1)/2 + 1; // maxinum possible with k splitter
    possible -= (k-mid)*(k-mid-1)/2; // remove possibilities with 1 to mid splitter
    possible += k-mid-1;
    
    return possible >= n;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned ll n,k;
    cin >> n >> k;

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    unsigned ll l = 0, h = k; // possible range for binary search.
    unsigned ll ans;
    bool check = false;
    while(l <= h){
        unsigned ll mid = l + (h-l)/2;

        if(isPossible(n,mid,k)){
            h = mid-1;
            ans = mid;
            check = true;
        }else{
            l = mid+1;
        }
    }
    if(check)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
