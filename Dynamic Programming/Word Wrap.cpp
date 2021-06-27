// Problem Link : https://practice.geeksforgeeks.org/problems/word-wrap1646/1#
    int solveWordWrap(vector<int>nums, int k) 
    {
        int n = nums.size();
        if(n == 1){ // if size of array is 1 then we will return 0 because one word will always fit in ont linr
            return 0;
        }
        int arr[n]; // dp array
        arr[0] = (k - nums[0])*(k - nums[0]);// adding 1st word in new line
        int len = 0;
        int j = 0;
        for(int i = 1; i < n-1; i++){
            len = nums[i]; // updating len it represents the characters in the line
            arr[i] = (k-nums[i])*(k-nums[i]) + arr[i-1]; // adding comming word in new line as a possibility
            // traveling through all previous words and try to mearge them in single line
            for(j = i-1; j >= 0; j--){ 
                if(len + nums[j] + 1 <= k){
                    len += nums[j]+1;
                    if(j-1 >= 0)
                        arr[i] = min((k-len)*(k-len) + arr[j-1],arr[i]); // new cost will be minimum of current cost and previous cost + cost of current line after adding some words
                    else
                        arr[i] = (k-len)*(k-len); // we are able to add all words in single line so cost will be only cost of current line
                }else{ // when we can not add word in silgle line we break the line
                    break;
                }
            }
        }
        len = nums[n-1]; // filling last cell is special because we there is no need to add cost of last line
        arr[n-1] = arr[n-2]; // if we add this word in new line
        // traveling through all previous words and try to mearge them in single line
        for(j = n-2; j >= 0; j--){
            if(len + nums[j] + 1 <= k){
                len += nums[j]+1;
                if(j-1 >= 0)
                    arr[n-1] = min(arr[j-1],arr[n-1]); // we will only consider cost till last word as cost of previous line because cost of last line is 0
                else
                    arr[n-1] = 0; // we can add all words in single line so cost will be 0
            }else{
                break;
            }
        }
        return arr[n-1];
    } 
