// Problem Link : https://codeforces.com/contest/1569/problem/A
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

        string str;
        cin >> str;

        int l = -2, r = -2;

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == 'a')
                sum += 1;
            else
                sum -= 1;
            
            if(mp.count(sum) == 1){
                 l = mp[sum]+1;
                 r = i;
                 break;
            }
            if(sum == 0){
                l = 0;
                r = i;
                break;
            }
            mp[sum] = i;
        }
        cout << l+1 << " " << r+1 << endl;
    }
    return 0;
}
