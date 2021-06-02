// Problem Link : https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1
    static bool comparator(int a, int b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        
        return c1 > c2;
    }
    
    // Main function
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,comparator);
    }