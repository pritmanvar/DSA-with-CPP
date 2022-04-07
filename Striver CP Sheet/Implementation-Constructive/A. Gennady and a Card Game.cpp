// Problem : https://codeforces.com/problemset/problem/1097/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    bool ans = false;
    for(int i = 0; i < 5; i++){
        string temp;
        cin >> temp;

        if(str[0] == temp[0] || str[1] == temp[1])
            ans = true;
    }
    if(ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
