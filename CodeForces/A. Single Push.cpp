// Problem Link : https://codeforces.com/problemset/problem/1253/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        int a[n];
        int b[n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        int check = 0;
        int k = 0;
        bool ans = true;
        bool isNegative = false;
        for(int i = 0; i < n; i++){
            if(b[i]-a[i] < 0){ 
                isNegative = true;
                break;
            }
            if(check == 0 && a[i] == b[i]){ 
                continue;
            }
            if(check == 0 && a[i] != b[i]){
                k = b[i]-a[i];
                check = 1;
            }else if(check == 1 && b[i] - a[i] == k){
                continue;
            }else if(check == 1 && b[i] == a[i]){
                check = 2;
            }else if(check == 1 && b[i]-a[i] != k){
                ans = false;
                break;
            }else if(check == 2 && b[i] != a[i]){
                ans = false;
                break;
            }
        }
        if(isNegative){
            cout << "NO\n";
            continue;
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
