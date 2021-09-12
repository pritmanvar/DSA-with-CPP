// Problem Link : https://practice.geeksforgeeks.org/problems/smaller-on-right4318/1/?track=P100-Binary%20Search%20Tree&batchId=197#
int countSmallerRight(int arr[], int n) {
    set<int> st;
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        st.insert(arr[i]); // insert element into the set
        
        // find the first element that is lower than arr[i]
        auto it = st.lower_bound(arr[i]);
        // Find the distance between above found element 
        // and the beginning of the set using distance function
        if(distance(st.begin(),it) > ans)
            ans = distance(st.begin(),it);
    }
    return ans;
}
