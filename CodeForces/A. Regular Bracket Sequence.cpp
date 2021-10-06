// Problem Link : https://codeforces.com/problemset/problem/1469/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string str;
        cin >> str;

        // if length is odd then it can't be regular
        if(str.length()%2 == 1){
            cout << "NO\n";
            continue;
        }
        int que=0,open=0,close=0; // to count question mark, opening and closing brackets

        bool got = false; // does we get our answer?

        // traverse from begining
        for(int i = 0; i < str.length(); i++){
            str[i] == '?' ? que++ : str[i] == '(' ? open++ : close++; // update count.

            // if at any point number of closing bracket is greater than opening + ? then we can't regulate sequence.
            // so answer will be no
            if(open+que < close){
                got = true;
                break;
            }
        }
        if(got){
            cout << "NO\n";
            continue;
        }
        que = open = close = 0;
        // will check same but starting from ending.
        for(int i = str.length()-1; i >= 0; i--){
            str[i] == '?' ? que++ : str[i] == '(' ? open++ : close++;

            // here close+que < open then answer will be NO
            if(close+que < open){
                got = true;
                break;
            }
        }
        if(got){
            cout << "NO\n";
            continue;
        }

        // if we can't found any case where answer is NO then at last answer will be YES
        cout << "YES\n";
    }
    return 0;
}
