// Problem Link : https://www.codechef.com/JUNE21C/problems/BITTUP

#include<bits/stdc++.h>
#define N 1000000007
using namespace std;

long long power(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        long long int n,m;
        cin >> n >> m;
        long long int pw = power(2,n,N)-1;
        cout << (power(pw,m,N)%N) << endl;
    }
    return 0;
}
