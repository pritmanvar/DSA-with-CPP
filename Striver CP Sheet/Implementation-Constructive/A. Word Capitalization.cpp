// Problem Link : https://codeforces.com/problemset/problem/281/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    if(str[0] >= 'a' && str[0] <= 'z'){
        str[0] += 'A' - 'a';
    }
    for(int i = 1; i < str.length(); i++){
        if(str[i] == ' ' && i < str.length()){
            if(str[i] >= 'a' && str[i] <= 'z')
                str[i] += 'A' - 'a';
        }
    }
    cout << str << endl;
    return 0;
}
