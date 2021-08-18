// Problem Link : https://codeforces.com/contest/1560/problem/C

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        int x = sqrt(n);
        int one = x+1;
        int r,c;
        
        if(x*x == n){
            r = x;
            c = 1;
        }else if(x*x + x + 1 == n){
            r = x+1;
            c = x+1;
        }else if(((x*x) + x + 1) > n){
            r = n-(x*x);
            c = x+1;
        }else{
            r = x+1;
            c = (x+1)*(x+1) -n +1;
        }
        cout << r << " " << c << endl;
    }
    return 0;
}
