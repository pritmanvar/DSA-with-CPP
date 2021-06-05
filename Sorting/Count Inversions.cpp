// Problem Link :https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
    // Main ffunction is inversionCount.
    long long int merge(long long int arr[],long long int s,long long int m,long long int e){
        long long int left[m-s+1];
        long long int right[e-m];
        long long int count = 0;
        
        for(int i = s; i <= m; i++){
            left[i-s] = arr[i];
        }
        for(int i = m+1; i <= e; i++){
            right[i-m-1] = arr[i];
        }
        
        int i = 0;
        int j = 0;
        int k = s;
        
        while(i < e-m && j < m-s+1){
            if(right[i] < left[j]){
                 // here right has smaller element so in the left array m-s+1-j elements will be bigger then current element in right.
                count += m-s+1-j;
                arr[k] = right[i];
                i++;
                k++;
            }else{
                arr[k] = left[j];
                j++;
                k++;
            }
        }
        while(i < e-m){
            arr[k] = right[i];
            i++;
            k++;
        }
        while(j < m-s+1){
            arr[k] = left[j];
            j++;
            k++;
        }
        return count;
    }
    
    long long int mergeSort(long long int arr[],long long int s,long long int e){
        // basicly inverse is the sum of number of element which are bigger then current one at the left side.
        long long int ans1 = 0;
        long long int ans2 = 0;
        long long int ans3 = 0;
        if(s < e){
            long long int m = s + (e - s)/2;
            ans1 = mergeSort(arr,s,m);
            ans2 = mergeSort(arr,m+1,e);
            ans3 = merge(arr,s,m,e);
        }
        return ans1+ans2+ans3;
    }
    
    // Main Function
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
        
    }
