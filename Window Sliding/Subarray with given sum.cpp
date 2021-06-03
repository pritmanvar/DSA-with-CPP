// Problem Link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        vector<int> ans;
        vector<int> dp;
        int st = -1;
        int ed = 0;
        dp.push_back(arr[0]);
        // finding prefix sum
        for(int i = 1; i < n; i++){
            dp.push_back(dp[i-1] + arr[i]);
        }
        while(st < n && ed < n){
            if(st == -1){
                if(dp[ed] > s){
                    st++;
                }else if(dp[ed] < s){
                    ed++;
                }else{
                    ans.push_back(0+1);
                    ans.push_back(ed+1);
                    return ans;
                }
            }else{
                if(dp[ed] - dp[st] > s){
                    st++;
                }else if(dp[ed] - dp[st] < s){
                    ed++;
                }else{
                    ans.push_back(st+2);
                    ans.push_back(ed+1);
                    return ans;
                }
            }
        }
        ans.push_back(-1);
        return ans;
    }