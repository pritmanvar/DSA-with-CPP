// Problem Link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=-2&difficulty[]=-1&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]-2difficulty[]-1page1sortBysubmissionscategory[]sliding-window
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int maxi = INT_MIN;
        int sum = 0;
        // making array prefix su array
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        maxi = sum;
        // used window sliding technic
        for(int i = 1;i <= n-k; i++){
            sum += arr[i+k-1] - arr[i-1];
            maxi = max(maxi,sum);
        }
        return maxi;
    }