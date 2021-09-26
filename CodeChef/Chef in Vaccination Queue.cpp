// Problem Link : https://www.codechef.com/START13B/problems/VACCINQ

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,p,x,y;
        cin >> n >> p >> x >> y;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            
            if(i < p-1)
            ans += temp == 1 ? y : x;
        }
        cout << ans+y << endl;
    }
    return 0;
}
