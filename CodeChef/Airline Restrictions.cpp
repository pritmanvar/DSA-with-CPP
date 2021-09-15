// Problem Link : https://www.codechef.com/SEPT21B/problems/AIRLINE

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;

        bool ans = false;
        if(a+b <= d && c <= e){
            ans = true;
        }else if(a+c <= d && b <= e){
            ans = true;
        }else if(b+c <= d && a <= e){
            ans = true;
        }

        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
