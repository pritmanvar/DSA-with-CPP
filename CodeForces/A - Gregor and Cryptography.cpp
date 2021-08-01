// Problem Link : https://codeforces.com/contest/1549/problem/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        // n is prime number and n >= 5 so n must be odd
        // so n%2 == n%(n-1) == 1
        cout << 2 << " " << n-1 << endl;
    }
    return 0;
}
