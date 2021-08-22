// Problem Link : https://www.codechef.com/COOK132B/problems/EQDIFFER
#include<bits/stdc++.h>

using namespace std;

int main() 
{
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
        if(n < 3){ // if n is 1 or 2 then i don't need to delete anything because there is only one pair possible
            cout << 0 << endl;
        }else{
            int ans = n;
            for(auto i : mp){ // ans will be total number of element - max frequency 
                ans = min(ans,n-i.second);
            }
            if(ans == n-1){ // if all elements are distinct then i need to remove n-1 elements but i will remove n-2 element and make only 1 pair
                cout << n-2 << endl;
            }else{
                cout << ans << endl;
            }
        }
    }
    return 0;
}
