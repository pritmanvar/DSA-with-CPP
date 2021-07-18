// Problem Link : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n);
        ans[n-1] = -1; // there isn't any next greater at the last element so it's answer will be -1
        
        stack<long long> st;
        st.push(arr[n-1]); // adding last element in the stack
        
        for(int i = n-2; i >= 0; i--){ // we need next greater element so we will run loop from last
            // I need next greater element so i will remove element from the stack which are smaller then current
            while(st.size() != 0 && st.top() < arr[i]){
                st.pop();
            }
            
            //if stack is empty means there isn't any greater element on right else i will add top element of stack because it is next greater element
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            // adding current element into stack
            st.push(arr[i]);
        }
        return ans;
    }
