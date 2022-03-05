// Problem Link : https://codeforces.com/problemset/problem/723/A
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);

    cout << arr[1]-arr[0]+arr[2]-arr[1] << endl;

    return 0;
}
