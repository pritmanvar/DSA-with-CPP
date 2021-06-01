int maxSubarrayLinear(vector<int>& A){
        int maxLinear = A[0];
        int sum = A[0];
        for(int i = 1; i < A.size(); i++){
            sum = max(sum+A[i],A[i]);
            maxLinear = max(sum,maxLinear);
        }
        return maxLinear;
    }
    
    // Main Function
    int maxSubarraySumCircular(vector<int>& A) {
        int maxLinear = maxSubarrayLinear(A);
        if(maxLinear <= 0)//if maxliner sum is negative then we will return that else our algo will be wrong
            return maxLinear;
        int total = 0;
        // ginding total sum and make addition inviresse of every element
        for(int i = 0; i < A.size(); i++){
            total += A[i];
            A[i] = -A[i];
        }
        int minLinear = maxSubarrayLinear(A);// finding minimum sum in linear subarray
        //we will substract it from total sum to get max sum in circlar subarray and return max of linear and circular subarray.
        return max(maxLinear,total + minLinear);
    }
