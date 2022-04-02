// Problem Link : https://codeforces.com/problemset/problem/791/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float a,b;
    cin >> a >> b;
    
    int ans = 0;

    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
