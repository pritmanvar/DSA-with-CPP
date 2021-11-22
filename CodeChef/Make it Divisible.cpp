// Problem : https://www.codechef.com/COOK135B/problems/ALLDIV3

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

        vector<int> rem(3);
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            rem[temp%3]++;
        }
        int ans = min(rem[1],rem[2]);
        if(abs(rem[1]-rem[2])%3 == 0){
            ans += 2*abs(rem[2]-rem[1])/3;
        }else{
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}
