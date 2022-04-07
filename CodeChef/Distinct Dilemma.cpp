// Problem Link : https://www.codechef.com/START33B/problems/DISTDILEM

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

        ll sum = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            sum += temp;
        }
        if(sum == 1){
            cout << 1 << endl;
            continue;
        }
        ll i = 1;
        ll sum2 = 1;
        while(sum2 <= sum){
            i++;
            sum2 += i;
        }
        cout << i-1 << endl;
    }
    return 0;
}
