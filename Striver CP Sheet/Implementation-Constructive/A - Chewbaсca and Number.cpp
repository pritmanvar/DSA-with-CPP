#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ll n;
    cin >> n;
    
    string ans = "";
    while(n > 0){
        if(n%10 < 5){
            ans += to_string(n%10);
        }else{
            ans += to_string(9 - n%10);
        }
        n /= 10;
    }
    reverse(ans.begin(),ans.end());
    if(ans[0] == '0'){
        ans[0] = '9';
    }
    cout << stoll(ans) << endl;
    return 0;
}
 
