// Problem Link : https://codeforces.com/problemset/problem/339/A

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int freq[3] = {0};
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '+'){
            freq[str[i]-'1']++;
        }
    }
    if(freq[0]){
        cout << 1;
        freq[0]--;
    }else if(freq[1]){
        cout << 2;
        freq[1]--;
    }else if(freq[2]){
        cout << 3;
        freq[2]--;
    }
    for(int i = 0; i < 3; i++){
        while(freq[i]--){
            cout << '+' << i+1;
        }
    }
    cout << endl;
    return 0;
}
