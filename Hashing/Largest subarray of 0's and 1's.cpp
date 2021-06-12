//Problem Link : https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?category[]=sliding-window&amp;category[]=sliding-window&amp;page=1&amp;sortBy=submissions&amp;query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window%27
    int maxLen(int arr[], int n)
    {
        for(int i = 0; i < n; i++){ // Making all 0 to -1
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        // Now we will find 0 sum subarray.
        partial_sum(arr, arr+n, arr);// making array prefix sum subarray.
        int ans = 0;
        unordered_map<int,int> mp;
        // Finding 0 sum subarray
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                ans = i+1;
                continue;
            }
            if(mp.find(arr[i]) != mp.end()){
                if(ans < i-mp[arr[i]]){
                    ans = i-mp[arr[i]];
                }
            }else{
                mp[arr[i]] = i;
            }
        }
        return ans;
    }
