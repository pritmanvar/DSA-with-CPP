// Problem Link : https://www.codechef.com/AUG21B/problems/OLYRANK
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int g1,s1,b1,g2,s2,b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
        if(g1+s1+b1 > g2+s2+b2)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
