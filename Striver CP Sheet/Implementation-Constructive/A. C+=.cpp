// Problem Link : https://codeforces.com/problemset/problem/1368/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int a,b,n;
        cin >> a >> b >> n;

        int count = 0;
        while(a <= n && b <= n){
            if(a + (a+b) > b + (b+a)){
                b += a;
            }else{
                a += b;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
