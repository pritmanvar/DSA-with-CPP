// Problem Link : https://www.codechef.com/COOK134B/problems/ZEROONE/

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
        vector<int> zero;
        vector<int> one;
        vector<int> pre;
        pre.push_back(0);

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            if(i%2 == 0){
                zero.push_back(temp);
            }else{
                one.push_back(temp);
            }
        }
        sort(one.begin(),one.end());
        sort(zero.begin(),zero.end(),greater<int>());
        ll sum = 0;
        for(int i = 0; i < one.size(); i++){
            sum += one[i];
            pre.push_back(sum);
        }
        cout << endl;
        int ze = 0,o = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                cout << zero[ze] << " ";
                ans += (sum - pre[ze])*zero[ze];
                ze++;
            }else{
                cout << one[o] << " ";
                o++;
            }
        }
        cout << endl << ans << endl;
    }
    return 0;
}
