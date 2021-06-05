// Problem Link : https://practice.geeksforgeeks.org/problems/longest-equal-prefix3139/1/?category[]=prefix-sum&category[]=prefix-sum&difficulty[]=-1&page=1&sortBy=submissions&query=category[]prefix-sumdifficulty[]-1page1sortBysubmissionscategory[]prefix-sum
int findIndex(int arr[], int X, int Y, int N)
{
    // Your code goes here
    int nx = 0;// number of X
    int ny = 0;// number of Y
    int indx = -1;
    // counting number of X and Y and marked 1st index where X or Y will appear
    for(int i = N-1;i >= 0;i--){
        if(arr[i] == X){
            nx++;
            indx = i;
        }else if(arr[i]==Y){
            ny++;
            indx = i;
        }
    }
    
    int ans = N-1;// Assuming that longest equal prefix if length of n-1
    // while number of X and number of Y is different we will remove element from last and update ans
    while(nx != ny){
        if(arr[ans] == X){
            nx--;
        }else if(arr[ans] == Y){
            ny--;
        }
        ans--;
    }
    // ans is less then indx means there is such subarray is not possible mecause X or Y appears 1st time at index "indx"
    if(ans < indx){
        return -1;
    }else{
        return ans;
    }
}