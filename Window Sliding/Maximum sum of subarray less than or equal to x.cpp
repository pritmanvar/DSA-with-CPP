// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    long long int maxi = LLONG_MIN;
	    // making array prefix sum array
	    for(int i = 1; i < n; i++){
	        arr[i] += arr[i-1];
	    }
	    int st = -1;
	    int ed = 0;
	    // used 2 pointer algo
	    while(ed < n){
	        if(st == -1){
	            if(arr[ed] == sum){
	                return sum;
	            }else if(arr[ed] < sum){
	                maxi = max(arr[ed],maxi);
	                ed++;
	            }else{
	                st++;
	            }
	        }else{
	            if(arr[ed] - arr[st] == sum){
	                return sum;
	            }else if(arr[ed] - arr[st] < sum){
	                maxi = max(arr[ed]-arr[st],maxi);
	                ed++;
	            }else{
	                st++;
	            }
	        }
	    }
	    return maxi;
	}
