// Problem Link : https://www.codechef.com/START33B/problems/NONADJFLIP

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
        int n;
        cin >> n;
        string str;
        cin >> str;

        int ans = 0, last = -2;
        bool isPresent = false;
        for(int i = 0; i < n; i++){
            if(str[i] == '1'){
                ans = 1;
                if(i-last == 1){
                    isPresent = true;
                }else{
                    str[i] = '0';
                    last = i;
                }
            }
        }
        if(isPresent == false){
            cout << ans << endl;
        }else{
            cout << 2 << endl;
        }
    }
    return 0;
}
