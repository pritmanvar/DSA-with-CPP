// Problem Link : https://www.codechef.com/START5C/problems/CYCLICQD
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // if 2 sum of opposite corners are 180 then print yes else no
        if(a+c == 180 && b+d == 180){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
