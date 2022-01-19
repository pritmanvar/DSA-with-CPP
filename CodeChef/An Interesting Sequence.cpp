// Problem Link : https://www.codechef.com/START22B/problems/INTSEQ/
// answer will be number of power of 2 in the k.

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int k;
        cin >> k;

        int ans = 0;

        while(k > 0 && k%2 == 0){
            ans++;
            k /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
