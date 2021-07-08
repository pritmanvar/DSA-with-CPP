// Problem Link : https://codeforces.com/contest/1543/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n;
        cin >> n;
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            sum += temp;
        }
        cout << (sum%n)*(n-(sum%n)) << endl;
    }
    return 0;
}
