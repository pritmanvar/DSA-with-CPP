// Problem Link : https://www.codechef.com/START10B/problems/REMONE
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        int a[n];
        int b[n-1];
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }
        sort(a,a+n,greater<int>());
        for(int i = 0; i < n-1; i++){
            cin >> b[i];
        }
        sort(b,b+n-1);
        int dif;
        for(int i = 0; i < n; i++){
            dif = b[0]-a[i];
            if(dif > 0){
                int j = 0;
                int k = n-2;
                while(j <= k && st.count(b[j]-dif) == 1 && st.count(b[k]-dif) == 1){
                    j++;
                    k--;
                }
                if(j > k){
                    break;
                }
            }
        }
        cout << dif << endl;
    }
    return 0;
}
