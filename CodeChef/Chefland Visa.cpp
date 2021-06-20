// Problem Link : https://www.codechef.com/COOK130C/problems/VISA
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int x1,x2,y1,y2,z1,z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

        if(x1 <= x2 && y1 <= y2 && z1 >= z2){ // if all condition follows then print yes
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
