// Problem Link : https://www.codechef.com/COOK135B/problems/MISSSUMS

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

        for(int i = 0; i < n; i++){
            cout << 2*i+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
