// Problem Link : https://www.codechef.com/LTIME103B/problems/MXMTRIO/

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ll t;
    cin >> t;
    for (ll z = 1; z <= t; z++){
        ll n;
        cin >> n;

        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll mn = LLONG_MAX;
        for(ll i = 0; i < n; i++){
            ll temp;
            cin >> temp;

            mn = min(temp,mn);

            if(pq.size() < 2){
                pq.push(temp);
            }else if(pq.top() < temp){
                pq.pop();
                pq.push(temp);
            }
        }

        ll a = pq.top();
        pq.pop();
        ll b = pq.top();

        ll ans = max((a-mn)*b,(b-mn)*a);

        cout << ans << endl;
    }
    return 0;
}
