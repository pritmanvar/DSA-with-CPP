// Problem Link : https://codeforces.com/problemset/problem/110/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int count = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '4' || str[i] == '7')
            count++;
    }
    if(count == 4 || count == 7)
        cout << "YES\n";
    else
        cout  << "NO\n";
    return 0;
}
