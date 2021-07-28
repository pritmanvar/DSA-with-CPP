// Problem Link : https://www.codechef.com/COOK131B/problems/CHFPLN

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        map<int,int> mp; // map of <element,frewuency>

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++; // adding all elements into map
        }
        int ans = 0;
        for(auto i : mp){
            if(i.second == 1){ // if frequency of current element is one then we can represent it by only one way
                ans++;
            }else{ // if it is greater then one then we can represent it by element-1 times or frequency times, element-1 times = (1,element-1),(2,element-2),...,(element-1,1)
                int tp = i.first - 1;
                ans += min(i.second,tp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
