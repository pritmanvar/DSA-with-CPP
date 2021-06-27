// Problem Link : https://www.codechef.com/LTIME97B/problems/FALSNUM/
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        string num;
        cin >> num;

        // we can add 1 at strting or arr 0 at 2nd digit to make number smaller
        string str1 = "1"+num; 
        string str2 = "" + num.substr(0,1) + "0" + num.substr(1,num.length()-1);

        if(str1 < str2){
            cout << str1 << endl;
        }else{
            cout << str2 << endl;
        }
    }
    return 0;
}
