//Problem Link : https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
int minSwap(int *arr, int n, int k) {
    // Complet the function
    int Smaller = 0;//This will store number of elements which are Smaller then k.
    for(int i = 0; i < n; i++){
        if(arr[i] <= k)
            Smaller++;
    }
    int ans=0;
    int mini;
    //for the 1st window of length smaller we will find how many elements are greater then k
    //we have to swap then with the elements which are less or equal to k
    //so if we want to get k together in this window then answer will be ans
    for(int i = 0; i < Smaller; i++){
        if(arr[i] > k)
            ans++;
    }
    mini = ans;
    //traverse throigh all window and find minimum swaps required for k together
    for(int i = 1; i <= n-Smaller; i++){
        if(arr[i-1] > k)//if leaving element is greater than k then we will decrement the ans
            ans--;
        if(arr[i+Smaller-1] > k)//if leaving element is greater than k then we will increment the ans
            ans++;
        mini = min(ans,mini);
    }
    return mini;
}
