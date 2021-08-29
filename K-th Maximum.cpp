// Problem Link : https://www.codechef.com/LTIME99B/problems/KMAX2/
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;
        long long int ans = 0;
        int arr[n];

        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            mx = max(mx,arr[i]);
        }

        for(int i = 0; i < n; i++){
            if(arr[i] == mx && i >= k-1){
                ans += n-i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
