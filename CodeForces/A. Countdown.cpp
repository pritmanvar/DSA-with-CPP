// Problem Link : https://codeforces.com/problemset/problem/1573/A

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
        int count = 0;
        // i have to make string 0 so if there is a non zero degit x then i need atleast x moves to make it 0
        // and if it is not at last position then i need one extra move to bring that digit at last position because i can use operation 1 on only last position.
        for(int i = 0; i < str.length(); i++){
            count += str[i]-'0';
            if(str[i] != '0' && i != str.length()-1)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
