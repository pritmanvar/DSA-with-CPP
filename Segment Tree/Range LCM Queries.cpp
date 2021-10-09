// Problem Link : https://practice.geeksforgeeks.org/problems/range-lcm-queries3348/1/?track=P100-Segment-Tree&batchId=197#

// arr : given array
// n : size of the array
// qs and qe are L and R respectively given in the problem to denotes range
// st : segment tree of the array arr

// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

// Function to get LCM of elements between index qs and qe
ll Get(ll* st, int ss, int se, int qs, int qe, int ind){
    if(qs > se || qe < ss) // if query is out of current segment
        return 1;
    if(qs <= ss && qe >= se) // if current segment is inside of query
        return st[ind];
    
    // call for it's left and right subtree
    int m = ss + (se-ss)/2;
    ll lcm1 = Get(st,ss,m,qs,qe,2*ind+1);
    ll lcm2 = Get(st,m+1,se,qs,qe,2*ind+2);
    
    return lcm(lcm1,lcm2); // return lcm of both.
}
ll getLCM(ll *st, int *arr, int n, int qs, int qe) 
{
    return Get(st,0,n-1,qs,qe,0);
}

// Function to update the value.
void Update(ll* st, int ss, int se, int i, int ind, int new_val){
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
    
    st[ind] = lcm(st[2*ind+1],st[2*ind+2]); // update lcm of current node
}
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    Update(st, 0, n-1, index, 0, new_val);
}
