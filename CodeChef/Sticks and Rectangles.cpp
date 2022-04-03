// Problem Link : https://www.codechef.com/COOK140B/problems/RECSTI

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

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }


        int pairs = 0;
        int ans = 0;
        for(auto pr : mp){
            pairs += pr.second/2;
            ans += pr.second%2;
        }
        pairs += ans;

        if(pairs%2 == 0){
            cout << ans << endl;
        }else{
            cout << ans + 2 << endl;
        }
    }
    return 0;
}
