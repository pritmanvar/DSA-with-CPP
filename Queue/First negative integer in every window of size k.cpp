// Problem Link : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    queue<long long> q;
    vector<long long> ans;
    
    // I will add elements in the queue if and only if it is negative
    // because we want 1st negative number from the window
    
    // adding elements of 1st window in the queue if it is negative
    for(long long i = 0; i < K; i++){
        if(A[i] < 0)
            q.push(i);
    }
    
    // if there is any negative element in the 1st window then i will add 1st element in the ans else add 0
    if(q.size()>0)
        ans.push_back(A[q.front()]);
    else
        ans.push_back(0);
    
    // processing other windows
    for(long long i = K; i < N; i++){
        // if there is any element who is from previous window then i will remove that from queue
        if(q.size() > 0 && q.front() == i-K)
            q.pop();
        
        // if comming element is negative then i will add that in the queue
        if(A[i] < 0)
            q.push(i);
        
        // if there is any negative element in the current window then i will add 1st element in the ans else add 0
        if(q.size()>0)
            ans.push_back(A[q.front()]);
        else
            ans.push_back(0);
    }
    return ans;
 }
