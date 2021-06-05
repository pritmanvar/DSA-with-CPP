//Problem Link : https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

// Used two pointer algorithm
bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int st = 0;
    int ed = 0;
    while(st <= ed && ed < size){
        if(arr[ed] - arr[st] < n){
            ed++;
        }else if(arr[ed] - arr[st] > n){
            st++;
        }else{
            return true;
        }
    }
    return false;
}