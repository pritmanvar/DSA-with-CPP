// Problem Link : https://practice.geeksforgeeks.org/problems/range-gcd-queries3654/1/?track=P100-Segment-Tree&batchId=197#
    
    // function to get gdc of index qs to qe
    int Get(int st[], int ss, int se, int qs, int qe, int ind){
        if(qs > se || qe < ss) // if query is out of current segment
            return 0;
        if(qs <= ss && qe >= se) // if current segment is inside of query
            return st[ind];
        
        // call for it's left and right subtree
        int m = ss + (se-ss)/2;
        int gcd1 = Get(st,ss,m,qs,qe,2*ind+1);
        int gcd2 = Get(st,m+1,se,qs,qe,2*ind+2);
        
        return __gcd(gcd1,gcd2); // return gcd of both.
    }
    int findRangeGcd(int l, int r, int st[], int n) 
    {
        return Get(st,0,n-1,l,r,0);
    }
    // function to update the value.
    void Update(int st[], int ss, int se, int i, int ind, int new_val){
        if(i < ss || i > se) // if index is out of current segment
            return;
        
        if(i == ss && i == se){ // if current segment represent only this index
            st[ind] = new_val;
            return;
        }
        
        // call for it's left and right subtree.
        int m = ss + (se-ss)/2;
        Update(st,ss,m,i,2*ind+1,new_val);
        Update(st,m+1,se,i,2*ind+2,new_val);
        
        st[ind] = __gcd(st[2*ind+1],st[2*ind+2]); // update gcd of current node
    }
    void updateValue(int index, int new_val, int *arr, int st[], int n) 
    {
        Update(st,0,n-1,index,0,new_val);
        arr[index] = new_val;
    }
