// Problem Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
    vector<int> findTwoElement(int arr[], int n) {
        // Traverse the array. 
        // While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. 
        // If something is already marked negative then this is the repeating element. 
        // To find missing, traverse the array again and look for a positive value.
        vector<int> ans(2);
        for(int i = 0; i < n; i++){
            if(arr[abs(arr[i])-1] > 0){
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            }else{
                ans[0] = abs(arr[i]);
            }
        } 
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
