// Problem Link : https://www.codechef.com/AUG21B/problems/SPCTRIPS
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
        for(int c = 1; c <= n; c++){
            int b = c;
            while(b <= n){
                ans += (n-c)/b;
                b += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
