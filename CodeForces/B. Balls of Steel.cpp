// Problem Link : https://codeforces.com/problemset/problem/1450/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;

        vector<pair<int,int>> points;
        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;

            points.push_back({x,y});
        }
        
        int ans = -1;
        for(int i = 0; i < n; i++){
            int temp = 1;
            // from point 'i' i will search for a point 'j' whose distance is more than k
            // and if such point is not exists then answer for current test case will be 1.
            for(int j = 0; j < n; j++){
                if(abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second) > k){
                    temp = -1;
                }
            }
            if(temp == 1){
                ans = 1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
