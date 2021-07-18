// Problem Link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        // Adding all person in the stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            // i will take 2 persons from top
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // if 'a' knows 'b' then 'a' can't be celebrity so i will add 'b' in the stack again
            // and if 'a' doesn't know 'b' then 'b' can't be celebrity so i will add 'a' in the stack again
            if(M[a][b] == 1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int a = st.top();
        st.pop();
        // i will check that last element is celebrity or not
        // if not then i will return -1
        for(int i = 0; i < n; i++){
            if(M[a][i] == 1){
                return -1;
            }
            if(M[i][a] == 0 && i != a){
                return -1;
            }
        }
        return a;
    }
