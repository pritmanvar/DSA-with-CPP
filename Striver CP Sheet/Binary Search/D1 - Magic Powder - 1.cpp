// Problem Link : https://codeforces.com/contest/670/problem/D1
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

// will check that Apollinaria can bake 'number' cookies or not.
bool isPossible(int number, int a[], int b[], int n, int k){
    for(int i = 0; i < n; i++){
        if(b[i] < number*a[i]){
            if(k < number*a[i]-b[i])
                return false;
            else
                k -= number*a[i]-b[i];
        }
    }
    return true;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int l = 0,h = 0; // scope of cookies -> minimum Apollinaria can bake 0 and maximum she can bake h cookies.
    for(int i = 0; i < n; i++){ // setting value of 'h' for binary search
        if(a[i] > 0){
            h = max(h,k+b[i]/a[i]);
        }
    }

    int ans = 0;
    while(l <= h){
        int mid = l + (h-l)/2;

        if(isPossible(mid, a, b, n, k)){ // it is possible to bake mid cookies so now i will try to maximize it and mark mid as possible answer.
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    cout << ans << endl; // Print answer.
    return 0;
}
