// Problem Link : https://www.codechef.com/JUNE21C/problems/CHFHEIST

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        unsigned long long int days,d,p,q;
        cin >> days >> d >> p >> q;

        unsigned long long int  n = days/d;
        unsigned long long int  r = days%d;

        unsigned long long int ans = d*((n*p) + ((q*(n-1)*n)/2)) + r*(p + (n*q));

        cout << ans << endl;
    }
    return 0;
}
