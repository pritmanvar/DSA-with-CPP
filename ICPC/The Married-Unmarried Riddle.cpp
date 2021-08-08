// Problem Link : https://codedrills.io/contests/icpc-amritapuri-2020-preliminary-round/problems/the-married-unmarried-riddle

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string s;
        cin >> s;

        bool ans = false;
        int i = 0;
        while(i < s.length()){
            if(s[i] == 'M'){
                if(i+1 < s.length()){
                    if(s[i+1] == 'U'){
                        ans = true;
                        break;
                    }else if(s[i+1] == '?'){
                        while(i+1 < s.length() && s[i+1] == '?'){
                            i++;
                        }
                        if(i+1 < s.length() && s[i+1] == 'U'){
                            ans = true;
                            break;
                        }
                    }
                }
            }
            i++;
        }
        if(ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
