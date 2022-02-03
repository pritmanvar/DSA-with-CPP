// Problem Link : https://www.codechef.com/START24B/problems/ANTI_PAL

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        string str;
        cin >> str;

        sort(str.begin(),str.end());
        int i = 0, j = n-1, s = 0; // s is is index of last char that i swaped + 1. that means next chat i have to swap if there is condition of palindrome.
        while(i <= j){
            if(str[i] == str[j]){
                swap(str[s],str[j]);
                s++;
            }
            i++;
            j--;
        }

        i = 0, j = n-1;
        bool ans = true;
        while(i <= j){ // if at any place condition of palindrome is true
            if(str[i] == str[j]){
                ans = false;
                break;
            }
            i++;
            j--;
        }
        if(ans){
            cout << "YES\n";
            cout << str << endl;
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
