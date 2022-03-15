// Problem Link : https://codeforces.com/problemset/problem/144/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int mn = INT_MAX, mx = INT_MIN;
    int mni = -1, mxi = -1;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        if(mn >= temp){
            mn = temp;
            mni = i;
        }
        if(mx < temp){
            mx = temp;
            mxi = i;
        }
    }
    if(mni < mxi){
        cout << mxi+n-mni-1-1 << endl;
    }else{
        cout << mxi+n-mni-1 << endl;
    }
    return 0;
}
