// Problem Link : https://www.codechef.com/AUG21B/problems/PROBDIFF
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        unordered_map<int,int> m;
        for(int i = 0; i < 4; i++){
            int temp;
            cin >> temp;
            m[temp]++;
        }
        if(m.size() >= 3){
            cout << 2 << endl;
        }else if(m.size() == 2){
            if(m.begin()->second == 2)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
