// Problem Link : https://www.codechef.com/SEPT21B/problems/TRAVELPS

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,a,b;
        cin >> n >> a >> b;
        string str;
        cin >> str;

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '0')
                ans += a;
            else    
                ans += b;
        }
        cout << ans << endl;
    }
    return 0;
}
