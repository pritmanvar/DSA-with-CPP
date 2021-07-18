// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> pre; 
        long long int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            // here ith element is removing element on the top of stack because that is greater than ith element
            // that means next smaller element of the element who is at the top of stack is ith element
            // and previous smaller will be element just below it
            // so if we consider height of hidtogram as the element at top of stack
            // then next smaller will be ith element and previous smaller will be element who is just below to it
            // so with help of these 2 we can find area of current histogram and we will take max of these all
            while(pre.size() != 0 && arr[pre.top()] >= arr[i]){
                int curr = pre.top();
                pre.pop();
                // '?' is used to handle special case when element has not any previous smaller element
                long long temp = (pre.empty() ? i : (i-pre.top()-1))*arr[curr];
                ans = max(ans,temp);
            }
            pre.push(i);
        }
        // now elements which are present the the stack that has not any next smaller element
        while(pre.size() != 0){
            int curr = pre.top();
            pre.pop();
            // '?' is used to handle special case when element has not any previous smaller element
            long long temp = (pre.empty() ? n : n-pre.top()-1)*arr[curr];
            ans = max(ans,temp);
        }
        return ans;
    }
