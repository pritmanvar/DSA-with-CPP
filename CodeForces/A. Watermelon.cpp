// Problem Link : https://codeforces.com/problemset/problem/4/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    // if number is even then answer will YES but 2 is special case in that i can only devide in part of 1-1 so in that case answer will be NO
    if(t%2 == 0 && t != 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
