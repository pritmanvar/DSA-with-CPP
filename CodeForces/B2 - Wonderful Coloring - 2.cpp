// Problem Link : https://codeforces.com/contest/1551/problem/B2

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);
        vector<int> ans(n);
        unordered_map<int,int> freq; // To store frequency of every element
        unordered_map<int,vector<int>> index; // it will store the index when element is present

        // taking input and updating both maps
        for(int i = 0; i < n; i++){
            cin >> arr[i];

            index[arr[i]].push_back(i);
            freq[arr[i]]++;
        }
      
        int elements = 0; // it will store sum of all occurance of elements which frequency is less than k

        for(auto i : freq){
            if(i.second >= k){
                // if frequency is greater than k then i will move to every index of that element and assign them different color
                for(int j = 0; j < k; j++){
                    ans[index[i.first][j]] = j+1;
                }
            }else{ // of frequency is less than k then add its occurances into elements variable
                elements += i.second;
            }
        }
      
        // Now there are 'element' elements remaining so we can give all colors elements/k times
        // so number of elements we can color is elements/k*k
        int count = elements/k*k; 
        int color = 0; // to select that which color i have to give to the this element

        // check for all elements
        for(auto i : freq){
            // if its frequency is greater than k means we have considered it before.
            // its count is equal to 0 means we can't color more elements
            if(i.second < k && count != 0){
                //  i will move to every index of current element and assign them different color
                for(int j = 0; j < index[i.first].size(); j++){
                    if(count == 0)
                        break;
                    
                    ans[index[i.first][j]] = (color%(k))+1; // assiging color
                    color++; // updating color
                    count--; // updating count
                }
            }
        }
        
        // printing answer
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
