// Problem Link : https://codeforces.com/problemset/problem/702/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 1, mxans = 1;
    int ago;
    cin >> ago;

    for(int i = 1; i < n; i++){
        int temp;
        cin >> temp;

        if(temp > ago){
            ans++;
            ago = temp;
        }else{
            mxans = max(ans,mxans);
            ago = temp;
            ans = 1;
        }
    }
    cout << max(ans,mxans) << endl;
    return 0;
}
