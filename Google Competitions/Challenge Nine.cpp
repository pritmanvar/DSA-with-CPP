// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7997

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
        string n;
        cin >> n;

        ll sum = 0;
        for(int i = 0; i < n.length(); i++){
            sum += n[i] - '0';
        }
        if(sum%9 == 0){
            n = n.substr(0,1) + '0' + n.substr(1);
            cout << "Case #" << z << ": " << n << endl;
            continue;
        }
        int digit = 9 - sum%9;
        char dg = digit + '0';

        string ans = n + dg;
        for(int i = 0; i < n.length(); i++){
            ans = min(ans,n.substr(0,i)+dg+n.substr(i));
        }
      
        cout << "Case #" << z << ": " << ans << endl;
    }
    return 0;
}
