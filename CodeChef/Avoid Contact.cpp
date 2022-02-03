// Problem Link : https://www.codechef.com/START24B/problems/AVOIDCONTACT
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int x,y;
        cin >> x >> y;

        if(x == y){
            cout << 2*x-1 << endl;
        }else if(y == 0){
            cout << x << endl;
        }else{
            int ans = x-y;
            ans += (y-1)*2;
            ans += 2;

            cout << ans << endl;
        }
    }
    return 0;
}
