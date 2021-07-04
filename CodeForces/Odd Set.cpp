// Problem Link : https://codeforces.com/contest/1542/problem/A
// If number of even elements and odd elements are same then and only then we can split pairs into n pairs
#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n;
        cin >> n;
        int o = 0,e = 0;
        for(int i = 0; i < 2*n; i++){
            int temp;
            cin >> temp;
            if(temp%2 == 0)
                e++;
            else
                o++;
        }
        if(o==e)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
