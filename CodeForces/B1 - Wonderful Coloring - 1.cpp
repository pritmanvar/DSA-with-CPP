// Problem Link : https://codeforces.com/contest/1551/problem/B1

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string s;
        cin >> s;

        unordered_set<char> repeted;
        unordered_set<char> non_repeted;

        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            // if char is repeted then i will apply both color and remove that char and add that into repeted set to avoid same color at same char
            if(non_repeted.count(s[i]) == 1){
                ans++;
                non_repeted.erase(s[i]);
                repeted.insert(s[i]);
            }else if(repeted.count(s[i]) == 0){ // if number is not repeted
                non_repeted.insert(s[i]);
            }
        }

        ans += non_repeted.size()/2; // i can do half remening element to red and half to another color to follow rule

        cout << ans << endl;
    }
    return 0;
}
