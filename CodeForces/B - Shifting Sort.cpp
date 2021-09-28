// Problem Link : https://codeforces.com/contest/1579/problem/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        // i will use idea of selection sort algorithm.
        // in each move i will find minimum element from the remaining array and place that at the position of that element in sorted array.
        vector<tuple<int,int,int>> ans;
        for(int i = 0; i < n; i++){
            int mn = arr[i];
            int ind = i;
            // to find minimum element in the remaining array.
            for(int j = i; j < n; j++){
                if(mn > arr[j]){
                    mn = arr[j];
                    ind = j;
                }
            }
            // if l == r then it is not a valid rotation so i will not add that into answer.
            if(i+1 != ind+1){
                ans.push_back({i+1,ind+1,ind-i});
            }
            // rotate array between i to ind.
            reverse(arr+i,arr+ind);
            reverse(arr+i,arr+ind+1);
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
        }
    }
    return 0;
}
