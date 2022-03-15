// Problem Link : https://codeforces.com/problemset/problem/136/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans[n];

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        ans[temp-1] = i+1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
