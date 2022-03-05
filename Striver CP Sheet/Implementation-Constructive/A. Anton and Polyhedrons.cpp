// Problem Link : https://codeforces.com/problemset/problem/785/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string,int> mp;
    mp["Icosahedron"] = 20;
    mp["Cube"] = 6;
    mp["Tetrahedron"] = 4;
    mp["Dodecahedron"] = 12;
    mp["Octahedron"] = 8;

    int ans = 0;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        ans += mp[temp];
    }
    cout << ans << endl;
    return 0;
}
