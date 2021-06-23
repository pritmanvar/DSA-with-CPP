// Problem Link : https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int mx = 0; // store max number of 1
	    int ans = -1; // store answer
	    int r = 0;
	    int c = arr[0].size()-1;
	    int count = 0; // to track number of 1
	    while(r < arr.size() && c >= 0){
	        // if current element is 1 then we wil traverse remining row else skip that row because there can't be more one
	        if(arr[r][c] == 1){ 
	            count++;
	            c--;
	        }else{ 
	            if(mx < count){ // if count is max than mx then reset the ans
	                ans = r;
	                mx = count;
	            }
	            r++;
	        }
	    }
	    if(mx < count){
	        ans = r;
	        mx = count;
	    }
	    return ans;
	}
