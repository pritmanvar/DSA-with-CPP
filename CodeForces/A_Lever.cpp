// Problem Link : https://codeforces.com/problemset/problem/376/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;

    long long int left = 0;

    int n = str.length();
    int i = 0;
    while(i < n && str[i] != '^')i++; // searching for pivot

    // it there is a weight on the left side then i will add that into left and if there is a weight on the right then i will substract that from right
    // with help of last value of left i will deside that this is balance or not.
    
    int dist = 1;
    while(i-dist >= 0 && i+dist < n){
        if(str[i-dist] != '=')
            left += (str[i-dist]-'0')*dist;
        if(str[i+dist] != '=')
            left -= (str[i+dist]-'0')*dist;
        dist++;
    }
    while(i-dist >= 0){
        if(str[i-dist] != '=')
            left += (str[i-dist]-'0')*dist;
        dist++;
    }
    while(i+dist < n){
        if(str[i+dist] != '=')
            left -= (str[i+dist]-'0')*dist;
        dist++;
    }
    if(left == 0){
        cout << "balance" << endl;
    }else if(left < 0){
        cout << "right" << endl;
    }else{
        cout << "left" << endl;
    }
    return 0; 
}
