// Problem Link : https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1/?category[]=sliding-window&category[]=sliding-window&page=1&sortBy=submissions&query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window#
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int ans = 0;
	    partial_sum(arr,arr + n,arr); // making array pre-fix sum array
	    
	    unordered_map<int,int> mp; // map of reminder,index
	    for(int i = 0; i < n; i++){
	        if(arr[i] % k == 0){ // of current element is divisible by k then max ans till now will be current lenght
	            ans = i+1;
                continue;
	        }
	        
	        int m = (arr[i]%k + k)%k;
	        if(mp.find(m) != mp.end()){ // if current reminder is present in the map means we get a required subarray
	            ans = max(ans, i-mp[m]); // ans will max of current ans and current_index-first_index at which we found same reminder
	        }
	        if(mp.find(m) == mp.end()) // if reminder is not present then add that in map
	            mp[m] = i;
	    }
	    return ans;
	}
