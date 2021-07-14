// Problem Link : https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1#
	int search(int arr[], int N){
	    // used binnary search
	    // when if element at mid and next to it are same and our ans is at right of mid then number of element before mid must be even
	    // if ans is on left then element before mid must be odd
	    
        // when if element at mid and previous to it are same and our ans is at right of mid then number of element before mid must be odd
	    // if ans is on left then element before mid must be even
	    
	    int l = 0; 
	    int h = N-1;
	    
	    while(l <= h){
	        int m = l+(h-l)/2;
	        
	        if(m < N-1 && arr[m] == arr[m+1]){
	            if(m%2 == 0){
	                l = m+1;
	            }else{
	                h = m-1;
	            }
	        }else if(m > 0 && arr[m] == arr[m-1]){
	            if(m%2 == 0){
	                h = m-1;
	            }else{
	                l = m+1;
	            }
	        }else{
	            return arr[m];
	        }
	    }
	    return -1;
	}
