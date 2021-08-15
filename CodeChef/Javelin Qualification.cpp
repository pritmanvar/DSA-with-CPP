// Problem Link : https://www.codechef.com/START8B/problems/JAVELIN

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,m,x;
        cin >> n >> m >> x;

        set<int> st;
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if(temp >= m){
                st.insert(i+1);
            }else{
                pq.push({temp,i+1});
            }
        }
        int k = max((int)st.size(),x);
        cout << k << " ";
        x -= st.size();
        while (x > 0){
            int tp = pq.top().second;
            st.insert(tp);
            pq.pop();
            x--;
        }
        for(auto i : st){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
