// Problem Link : https://www.codechef.com/JUNE21C/problems/COCONUT/

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int xa,xb,XA,XB;
        cin >> xa >> xb >> XA >> XB;

        cout << ceil((double)XA/xa) + ceil((double)XB/xb) << endl;
    }
    return 0;
}
