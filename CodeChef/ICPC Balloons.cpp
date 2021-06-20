// Problem Link : https://www.codechef.com/COOK130C/problems/BALLOON
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        unordered_set<int> st;
        int n;
        cin >> n;
        int arr[n];

        bool check = true;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] <= 7){ // if element is less then 7 then and only then we will add that in set
                st.insert(arr[i]);
            }
            
            if(check && st.size() == 7){ // size is equal to 7 means there are all numbers from 1 to 7 so select this as answer and used check variable to get the min value
                ans = i+1;
                check = false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
