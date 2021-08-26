// Problem Link : https://codeforces.com/contest/1562/problem/A
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int l,r;
        cin >> l >> r;

        if(r/2 >= l){
            if(r%2 == 0)
                cout << r/2-1 << endl;
            else
                cout << r/2 << endl;
        }else{
            cout << r%l << endl;
        }
    }
    return 0;
}
