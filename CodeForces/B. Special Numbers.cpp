// Problem Link : https://codeforces.com/problemset/problem/1594/B

#include<bits/stdc++.h>
#define ll long long int
#define N 1000000007

using namespace std;
// binary exponention
long long power(long long a, long long b) 
{
    a%=N;
    long long res=1;
    while(b > 0) 
    {
        if (b & 1) res = res * a % N;
        a = a * a % N;
        b /= 2;
    }
    return res;
}
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;

        ll ans = 0;
        int pos = 0;
        // there is a pattern.
        // for kth num it will be value of equilent number in n base system if i convert binary of k to n base system.
        while(k > 0){
            if(k%2 == 1){
                ans = (ans+power(n,pos))%N;
            }
            pos++;
            k /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
