#include<bits/stdc++.h>

using namespace std;

// function to construct segment tree
// st->starting index
// ed->ending index
// ind->index in segment tree
int construct(int arr[],int segment_tree[], int st, int ed, int ind){
    if(st == ed){ // base case
        segment_tree[ind] = arr[st];
        return segment_tree[ind];
    }
    int m = st+(ed-st)/2;

    // call same function recursively for it's left half and right half
    segment_tree[ind] = construct(arr,segment_tree,st,m,2*ind+1) + construct(arr,segment_tree,m+1,ed,2*ind+2);

    return segment_tree[ind];
}
// function to get answer of getSum query
// ss->starting index of segment
// es->ending index of segment
// sq->starting index of query
// sq->ending index of query
// ind->index in segment tree
int getSum(int segment_tree[], int ss, int es, int sq, int eq, int ind){
    if(eq < ss || sq > es) // if current query is out of segment
        return 0;
    if(sq <= ss && eq >= es){ // if current segment is completly inside of segment
        return segment_tree[ind];
    }
    
    int m = ss + (es-ss)/2;

    // call same function for left and right subtree
    int sum = getSum(segment_tree,ss,m,sq,eq,2*ind+1) + getSum(segment_tree,m+1,es,sq,eq,2*ind+2);
    return sum; 
}

// function to perform update query.
// i->index which we have to update
// diff->difference between new and old value
// other varibles are same as getSum function.
void update(int segment_tree[], int ss, int es, int ind, int i, int diff){
    if(ss > i || es < i) // if i is not include in current segment.
        return;
    segment_tree[ind] += diff; // add difference into current node.
    if(ss == es) // if it is leaf then return
        return;
    
    // call same function for it's left and right subtree.
    int m = ss + (es-ss)/2;
    update(segment_tree,ss,m,2*ind+1,i,diff);
    update(segment_tree,m+1,es,2*ind+2,i,diff);
}
int main() 
{
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int segment_tree[4*n];
    construct(arr,segment_tree,0,n-1,0);
    
    int q;
    cout << "Enter the number of queries\n";
    cin >> q;

    for(int i = 0; i < q; i++){
        cout << "enter '1 x y' to perform getSum query where 'x' and 'y' is range of the query\n";
        cout << "enter '2 x y' to perform update query where 'x' is index and 'y' is new value of that inded\n";

        int t,x,y;
        cin >> t >> x >> y;

        if(t == 1){
            cout << getSum(segment_tree,0,n-1,x,y,0) << endl;
        }else{
            update(segment_tree,0,n-1,0,x,y-arr[x]);
            arr[x] = y;
        }
    }
    return 0;
}
