// Problem Link : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
    long long findMinDiff(vector<long long> a, long long n, long long m){

        sort(a.begin(),a.end());
        long long ans = INT_MAX;
        for(int i = m-1; i < n; i++){
            long long diff = a[i] - a[i-m+1];
            ans = min(ans,diff);
        }
        return ans;
    }