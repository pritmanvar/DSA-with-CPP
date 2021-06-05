// Problem Link : https://practice.geeksforgeeks.org/problems/nitika-and-her-queries4804/1/?category[]=prefix-sum&category[]=prefix-sum&page=1&sortBy=submissions&query=category[]prefix-sumpage1sortBysubmissionscategory[]prefix-sum#
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        // code here
        vector<int> ans;
        // making array xorsum
        for(int i = 1; i < N; i++){
            a[i] = a[i]^a[i-1];
        }
        for(int i = 0; i < Q; i++){
            int s = query[i][0];
            int e = query[i][1];
            
            int answ = a[N-1]^a[e-1]^a[s-2]; // used xor property : a^a = 0
            ans.push_back(answ);
        }
        return ans;
    }