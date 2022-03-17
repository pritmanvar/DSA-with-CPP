// Problem Link : https://codeforces.com/problemset/problem/116/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int inside = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        inside -= a;
        inside += b;

        ans = max(ans,inside);
    }
    cout << ans << endl;
    return 0;
}
