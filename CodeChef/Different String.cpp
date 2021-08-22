// Problem Link : https://www.codechef.com/COOK132B/problems/DIFSTR
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        vector<string> arr(n);
        string ans = "";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ans += "0";
        }
        sort(arr.begin(),arr.end()); // i will sort strings in lexicographical order
        int i = 0;

        // i will start from 0 and move ahead while i don't find any number which is not present and print the missing number
        while(ans == arr[i]){
            int pos = n-1;
            while(ans[pos] == '1'){
                ans[pos] = '0';
                pos--;
            }
            ans[pos] = '1';
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}
