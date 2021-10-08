// Problem Link : https://practice.geeksforgeeks.org/problems/range-min-max-queries4557/1/?track=P100-Segment-Tree&batchId=197#

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// ss and se : index range of current segment.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val


PII Get(PII *st, int ss, int se, int qs, int qe, int ind){
    
    if(qe < ss || qs > se) // if current query is out of segment
        return{INT_MAX,INT_MIN};
    if(qs <= ss && qe >= se){ // if current segment is completly inside of segment
        return st[ind];
    }
    
    int m = ss + (se-ss)/2;

    // call same function for left and right subtree
    PII ans1 = Get(st,ss,m,qs,qe,2*ind+1);
    PII ans2 = Get(st,m+1,se,qs,qe,2*ind+2);
    // return max and min of both answer.
    return {min(ans1.first,ans2.first),max(ans1.second,ans2.second)}; 
}
PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    return Get(st,0,n-1,qs,qe,0);
}

void update(PII* st, int ss, int se, int ind, int i, int new_val){
    if(ss > i || se < i) // if i is not include in current segment.
        return;
    // if current leaf represent ith node then update it and return.
    if(ss == i && se == i){
        st[ind].first = st[ind].second = new_val;
        return;
    }
    if(ss == se) // if it is leaf then return
        return;
    
    // call same function for it's left and right subtree.
    int m = ss + (se-ss)/2;
    update(st,ss,m,2*ind+1,i,new_val);
    update(st,m+1,se,2*ind+2,i,new_val);
    
    // update max of current segment according to its left and right subtree
    st[ind].first = min(st[2*ind+1].first,st[2*ind+2].first); 
    st[ind].second = max(st[2*ind+1].second,st[2*ind+2].second); 
}
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
    update(st,0,n-1,0,index,new_val);
    arr[index] = new_val;
}
