// Problem Link : https://codeforces.com/contest/1579/problem/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string str;
        cin >> str;

        int count = 0;
        // if number of 'B' is equal to number of 'A'+'C' then answer will be yes else answer will be no
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'B')
                count++;
            else
                count--;
        }
      
        if(count == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
