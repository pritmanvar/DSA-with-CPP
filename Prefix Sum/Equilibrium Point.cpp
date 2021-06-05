// Problem Link : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?category[]=prefix-sum&category[]=prefix-sum&difficulty[]=0&page=1&sortBy=submissions&query=category[]prefix-sumdifficulty[]0page1sortBysubmissionscategory[]prefix-sum
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long int* arr = new long long int[n];
        arr[0]=a[0];
        // making array prefix sum array
        for(int i = 1; i < n; i++){
            arr[i] = arr[i-1] + a[i];
        }
        // teaversing through all elements and check that that is equilibrium point or not
        for(int i = 0; i < n; i++){
            if(arr[i] - a[i] == arr[n-1] - arr[i]){
                return i+1;
            }
        }
        // if we didn't found anything then we will return -1
        return -1;
    }
