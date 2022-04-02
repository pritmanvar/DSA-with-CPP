// Problem Link : https://codeforces.com/problemset/problem/236/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    unordered_set<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        st.insert(str[i]);
    }
    if(st.size()%2 == 0){
        cout << "CHAT WITH HER!\n";
    }else{
        cout << "IGNORE HIM!\n";
    }
    return 0;
}
