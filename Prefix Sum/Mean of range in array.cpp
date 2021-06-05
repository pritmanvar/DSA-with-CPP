// Problem Link : https://practice.geeksforgeeks.org/problems/mean-of-range-in-array2123/1/?category[]=prefix-sum&amp;category[]=prefix-sum&amp;difficulty[]=0&amp;page=1&amp;sortBy=submissions&amp;query=category[]prefix-sumdifficulty[]0page1sortBysubmissionscategory[]prefix-sum
     vector<int> findMean(int arr[],int queries[],int n,int q)
    {
        // Complete the function
        vector<int> ans;
        int avg = 0;
        for(int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }
        for(int i = 0;i < q; i+=2){
            if(queries[i] == 0){
                avg = arr[queries[i+1]] / (queries[i+1] + 1);
            }else{
                avg = (arr[queries[i+1]] - arr[queries[i]-1]) / (queries[i+1] - queries[i] + 1);
            }
            ans.push_back(avg);
        }
        return ans;
    }