// Problem Link : https://www.codechef.com/START13B/problems/DIWALI1

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    long long int t;
    cin >> t;
    for (long long int z = 1; z <= t; z++){
        long long int p,a,b,c,x,y;
        cin >> p >> a >> b >> c >> x >> y;

        long long int fa = b+x*a;
        long long int fc = c+y*a;

        long long int mn = min(fa,fc);

        cout << p/mn << endl;
        
    }
    return 0;
}
