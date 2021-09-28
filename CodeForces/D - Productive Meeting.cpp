// Problem Link : https://codeforces.com/contest/1579/problem/D

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if(temp > 0)
            pq.push({temp,i});
        }
        int count = 0;
        vector<pair<int,int>> ans;
      
        // in each meet i will take 2 person with maximum sociability and arrange a meet between them.
        while(pq.size() > 1){
            pair<int,int> tp1 = pq.top();
            pq.pop();
            pair<int,int> tp2 = pq.top();
            pq.pop();

            ans.push_back({tp1.second,tp2.second}); // add current person into answer
          
            // if after meet their sociability is greater than 0 then i will add them in priority queue again
            if(tp1.first-1 > 0)
            pq.push({tp1.first-1,tp1.second});
            if(tp2.first-1 > 0)
            pq.push({tp2.first-1,tp2.second});
            count++; // increment count after every meet.
        }
        cout << count << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
        }
    }
    return 0;
}
