// Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1#
    
    // if element at ith index is smaller then its parent then this function will make heap balance
    void heapify_up(int i, vector<int>& arr){
        int p = (i-1)/2;
        if(p == -1 || arr[i] <= arr[p])
            return;
        
        swap(arr[i],arr[p]); 
        heapify_up(p, arr);
    }
    // to insert new data in the heap
    // i will insert data at the end and call heapify_up function to balance heap
    void insert(int n, vector<int>& arr){
        arr.push_back(n);
        heapify_up(arr.size()-1, arr);
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans = a; // initially ans will a because it is already heap
        // i will insert all elements of 2nd heap into my answer
        for(int i = 0; i < m; i++){
            insert(b[i],ans);
        }
        return ans;
    }
