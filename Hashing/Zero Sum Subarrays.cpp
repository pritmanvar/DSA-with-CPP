// Problem Link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
    long long int findSubarray(vector<long long int> arr, int n ) {
        long long int ans = 0;
        unordered_map<long long int,int> st; // map for the hashing
        partial_sum(arr.begin() , arr.end() , arr.begin()); // Making array prefixsum array
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){ // if prefixsum till this is 0 then this is a 0 sum subarray. (index 0 to i)
                ans++;
            }
            ans += st[arr[i]]; // if this sum is appeared ago then that index to this index is a 0 sum subarray.
            st[arr[i]]++; // updating frequancy of this sum in hash table
        }
        return ans;
    }
