// Problem Link : https://www.codechef.com/JULY21B/problems/XXOORR/

#include<bits/stdc++.h>

using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n,k;
        cin >> n >> k;
      
        vector<int> arr(n);
        int count = 0;
        int mx = INT_MIN;
      
        // taking input and number of odd number because its last bit will be set and max element because it would have largest number of bit
        // and also removing last bit of every number in it because we considered it in count
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i]%2 == 1){
                count++;
            }
            arr[i] = (arr[i] >> 1);
            mx = max(mx,arr[i]);
        }
        int ans = 0;
        
        // number of operations to unset last bit of every number if it is set
        while(count > 0){
            ans++;
            count -= k;
        }
      
        count = 0;
        while(mx != 0){
            // every time we will unset last bit of number and removing last bit from number as above
            for(int i = arr.size()-1; i >= 0; i--){
                if(arr[i] == 0){
                    arr.erase(arr.begin()+i);
                    continue;
                }
                if(arr[i]%2 == 1){
                    count++;
                }
                arr[i] = (arr[i] >> 1);
                if(count >= k){
                    ans++;
                    count -= k;
                }
            }
            if(count > 0){
                ans++;
                count = 0;
            }
            mx = (mx >> 1);
        }
        
        // printing answer
        cout << ans << endl;
    }
    return 0;
}
