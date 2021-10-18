// Problem Link : https://codeforces.com/problemset/problem/1538/C

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,l,r;
        cin >> n >> l >> r;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        long long ans = 0;
        for(int i = 0; i < n-1; i++){
            // number of element on the right who can make a pair with ith element will be
            // number of element whose value is less than r-arr[i]-number of element whose value is greater than l-arr[i].
            int pos1 = lower_bound(arr.begin()+i+1, arr.end(), l-arr[i])-arr.begin();
            int pos2 = upper_bound(arr.begin()+i+1, arr.end(), r-arr[i])-arr.begin();

            ans += pos2-pos1;
        }
        cout << ans << endl;
    }
    return 0;
}
