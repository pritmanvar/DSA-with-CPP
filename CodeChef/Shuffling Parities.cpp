// Problem Link : https://www.codechef.com/SEPT21B/problems/SHUFFLIN

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        int arr[n];

        int odd = 0;
        int even = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i]%2 == 0)
                even++;
            else
                odd++;
        }
        int ans = 0;
        ans += min(even,(int)ceil(n/2.0));
        ans += min(odd,n/2);

        cout << ans << endl;
    }
    return 0;
}
