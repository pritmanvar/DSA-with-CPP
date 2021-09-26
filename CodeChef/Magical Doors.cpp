// Problem Link : https://www.codechef.com/START13B/problems/MAGDOORS

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string str;
        cin >> str;

        int count = 0;
        if(str[0] == '0'){
            count = 1;
        }

        for(int i = 1; i < str.length(); i++){
            if(str[i] != str[i-1]){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
