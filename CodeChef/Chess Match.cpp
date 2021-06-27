// Problem Link : https://www.codechef.com/START5C/problems/BLITZ3_2
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n,a,b;
        cin >> n >> a >> b;
        // calculating ans by given equation
        int ans = 2*(180+n) - a - b;
        cout << ans << endl;
    }
    return 0;
}
