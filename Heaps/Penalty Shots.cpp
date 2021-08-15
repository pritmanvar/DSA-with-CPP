// Problem Link : https://www.codechef.com/START8B/problems/PENALTY

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int first = 0;
        int second = 0;

        for(int i = 0; i < 10; i++){
            int temp;
            cin >> temp;
            if(i%2 == 0 && temp == 1){
                first++;
            }else if(i%2 == 1 && temp == 1){
                second++;
            }
        }
        if(first > second)
            cout << 1 << endl;
        else if(first < second)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
