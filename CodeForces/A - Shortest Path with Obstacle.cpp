// Problem Link : https://codeforces.com/contest/1547/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int ax,ay,bx,by,fx,fy;
        cin >> ax >> ay;
        cin >> bx >> by;
        cin >> fx >> fy;
 
        int ans = abs(ax-bx) + abs(ay-by); // for the minnimum length of path we will move to same row and after go to same comoumn
        
        if(ax == bx || ay == by){
            // if f is in the our min path then and only then our length will be increment by 2
            if(ax == bx && fx == bx && fy < max(ay,by) && fy > min(ay,by)){
                ans += 2;
            }else if(ay == by && fy == by && fx < max(ax,bx) && fx > min(ax,bx)){
                ans += 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
