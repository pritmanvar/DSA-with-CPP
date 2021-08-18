// Problem Link : https://codeforces.com/contest/1560/problem/A

#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        int ans = 0;
        while(n > 0){
            ans++;
            while(ans%10 == 3 || ans%3 == 0){
                ans++;
            }
            n--;
        }
        cout << ans << endl;
    }
    return 0;
}
