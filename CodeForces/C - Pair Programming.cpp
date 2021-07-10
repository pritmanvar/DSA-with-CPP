// Problem Link : https://codeforces.com/contest/1547/problem/C

#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int k,n,m;
        cin >> k >> n >> m;
 
        int arr1[n];
        int arr2[m];
 
        for(int i = 0; i < n; i++){
            cin >> arr1[i];
        }
        for(int i = 0; i < m; i++){
            cin >> arr2[i];
        }
        vector<int> ans;
        bool check = true;
        int i = 0;
        int j = 0;
 
        while(i < n && j < m){
            // if both are tring to edit link which is not present then we will mark check as false and break the loop
            if(arr1[i] > k && arr2[j] > k){
                check = false;
                break;
            }
            // if Monocarp wants to add line or edit the line which is present then we will allow him
            if(arr1[i] <= k){
                if(arr1[i] == 0) // if he is adding a line then we will increment number of line too
                    k++;
                ans.push_back(arr1[i]);
                i++;
            }
            // if Polycarp is wants to add line or edit the line which is present then we will allow him
            if(arr2[j] <= k){
                if(arr2[j] == 0) // if he is addint a line then we will increment number of line too
                    k++;
                ans.push_back(arr2[j]);
                j++;
            }
        }
        // if some where both are tring to edit line which is not present then we will print -1 and continue to next test case
        if(check == false){
            cout << -1 << endl;
            continue;
        }
        // if now some changes by Monocarp are remaining then we will do that ans check for same
        while(i < n){
            if(arr1[i] <= k){
                if(arr1[i] == 0)
                    k++;
                ans.push_back(arr1[i]);
                i++;
            }else{
                check = false;
                break;
            }
        }
        // if now some changes by Polycarp are remaining then we will do that ans check for same
        while(j < m){
            if(arr2[j] <= k){
                if(arr2[j] == 0)
                    k++;
                ans.push_back(arr2[j]);
                j++;
            }else{
                check = false;
                break;
            }
        }
        
        // at last if check is false then we will print -1 else we will print our ans
        if(check){
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
