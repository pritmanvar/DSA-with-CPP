//Problem Link : https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
    int sb(int arr[], int n, int x)
    {
        //Creating Pre-fix Sum array
        for(int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }
        
        int st = -1;//It will point to the last element which is not including in the subarray basicly starting index
        int ed = 0; //It will point to the last element which is including in the subarray basicly ending index
        int len = INT_MAX; //length of subarry
        while(ed < n){
            if(st == -1){
                if(arr[ed] <= x){ //if sum of subarray is less or equal than given value then we will extend subarry by doint ed++
                    ed++;
                }else{ //if sum of subarray is greater than given value then we will update length if it is less than previous value and substract starting element
                    len = min(len,ed+1);
                    st++;
                }
            }else{//same steps as it. but it is needed because we can't access array element by negative index
                if(arr[ed] - arr[st] <= x){
                    ed++;
                }else{
                    st++;
                    len = min(len,ed - st + 1);
                }
            }
        }
        return len;
    }
