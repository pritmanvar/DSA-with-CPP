// Problem Link : https://codeforces.com/contest/1582/problem/C
#include<bits/stdc++.h>

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

        int ans = INT_MAX;

        // i will try to remove every char from string 
        for(char ch = 'a'; ch <= 'z'; ch++){
            int i = 0, j = n-1,temp = 0;
            while(i <= j){
                // if string is not palindrome because of current char
                if(str[i] != str[j]){
                    // if any of them is 'ch' then i can remove that to make string palindrome.
                    if(str[i] == ch){
                        temp++;
                        i++;
                    }else if(str[j] == ch){
                        temp++;
                        j--;
                    }else{ // if none of them is 'ch' then string can't be palindeom by removeing occurrence of 'ch'
                        break;
                    }
                }else{ // if it is palindrome then i will skip both char
                    i++;
                    j--;
                }
            }
            // if loop is not stoped due to break statement then it is possible to make string palindrome by removeing some occurrnece of any 1 char form string
            if(i > j){
                ans = min(ans,temp); // get min number that need to remove
            }
        }
        // if string can't be palindrome then ans will be -1
        if(ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
