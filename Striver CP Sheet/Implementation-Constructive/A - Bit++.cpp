#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int n;
    cin >> n;
    int ans = 0;
    for (int z = 1; z <= n; z++){
        string operation;
        cin >> operation;

        if(operation[1] == '+')
            ans++;
        else
            ans --;
    }
    cout << ans << endl;
    return 0;
}
 
