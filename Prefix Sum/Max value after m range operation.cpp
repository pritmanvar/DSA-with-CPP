// Problem Link : https://practice.geeksforgeeks.org/problems/max-value-after-m-range-operation4300/1/?category[]=prefix-sum&amp;category[]=prefix-sum&amp;difficulty[]=-1&amp;page=1&amp;sortBy=submissions&amp;query=category[]prefix-sumdifficulty[]-1page1sortBysubmissionscategory[]prefix-sum
	int findMax(int n, int m, int a[], int b[], int k[])
	{
	    // Your code goes here
	    vector<int> arr(n);
	    for(int i = 0; i < m; i++){
	        arr[a[i]] += k[i]; // We want effect of this element from this index so we add that
	        if(b[i] < n-1)
	            arr[b[i]+1] -= k[i]; // We want to remove effect of this element from next index of it so we substract that
	    }
	    int maxi = arr[0];
	    // doing prefix sum and taking max of that.
	    for(int i = 1;i < n; i++){
	        arr[i] += arr[i-1];
	        maxi = max(arr[i],maxi);
	    }
	    return maxi;
	}