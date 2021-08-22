// Problem Link : https://www.codechef.com/AUG21B/problems/CHFINVNT
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,p,k;
        cin >> n >> p >> k;

        int ans = (p%k) + p/k + 1;
        
        int i = 0;
        while(i < p%k){
            if((n-1-i)%k == 0){
                ans += (n-i-1)/k;
                i++;
            }else{
                ans += (n-1-i)/k*min(p%k-i,((n-1-i)%k));
                i += (n-1-i)%k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
