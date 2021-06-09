// Problem Link : https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
    int doUnion(int a[], int n, int b[], int m)  {
        //Add every element in unordered set and return size of set at last
        unordered_set<int> unin;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            unin.insert(a[i]);
            unin.insert(b[j]);
            i++;
            j++;
        }
        while(i < n){
            unin.insert(a[i]);
            i++;
        }
        while(j < m){
            unin.insert(b[j]);
            j++;
        }
        return unin.size();
    }
