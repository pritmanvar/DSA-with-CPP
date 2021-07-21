// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/?category[]=sliding-window&category[]=sliding-window&page=1&sortBy=submissions&query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window#
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq; // to preocess windows
        vector<int> ans; // to store answers
        
        // processing 1st window
        for(int i = 0; i < k; i++){
            // we will remove the element from back till that element is smaller than current one
            // because if that element is present any window then current element will also present in that window
            // so current that element can't be answer of that window
            while(dq.size() > 0 && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            
            // if current element is smaller than element at back then i will add that in the deque 
            // because there is a case when previous element is not present in the window but current element will present
            if(dq.size() == 0 || arr[dq.back()] > arr[i]){
                dq.push_back(i);
            }
        }
        // we have remove all smaller
        ans.push_back(arr[dq.front()]);
        
        for(int i = k; i < n; i++){
            // if there is a element present who is not included in current window then i will remove that
            if(dq.front() == i-k)
                dq.pop_front();
                
            // same process as the 1st window
            while(dq.size() > 0 && arr[dq.back()] <= arr[i])
                dq.pop_back();
            
            if(dq.size() == 0 || arr[dq.back()] > arr[i])
                dq.push_back(i);
            
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
