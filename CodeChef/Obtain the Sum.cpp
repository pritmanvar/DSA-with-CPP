// Problem Link : https://www.codechef.com/START11B/problems/BIGARRAY

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        long long int sum,n;
        cin >> n >> sum;

        if(n*(n+1)/2-sum <= 0 || n*(n+1)/2-sum > n){
            cout << -1 << endl;
        }else{
            cout << n*(n+1)/2-sum << endl;
        }
    }
    return 0;
}
