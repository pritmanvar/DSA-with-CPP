//Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i = n-1;
	    int j = 0;
	    
	    // By this loop we will moove all small element in 1st array and array 2 will contain all greater element then array 1
	    while(i >= 0 && j < m){
	        // Both arrays are sorted so if largest element in array 1 is greater then smallest element in array 2 then we will swap them
	        // Because smallest element should be in 1st array
	        if(arr1[i] > arr2[j]){
	            swap(arr1[i],arr2[j]);
	        }
            i--;
            j++;
	    }
	    // sort both arrays because all element is 1st array are smaller then minmum element in 2nd array
	    // but it is not necessary that both arrays are sorted array
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}