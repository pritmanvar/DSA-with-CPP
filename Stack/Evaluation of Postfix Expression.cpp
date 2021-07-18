//  Problem Link : https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i = 0; i < S.length(); i++){
            if(S[i] >= '0' && S[i] <= '9'){ // if current char is oparand then i will add this in the stack
                st.push(S[i]-'0');
            }else{ // if current char is oparator then i will pop 2 element from stack and after oparation i will push that in stack
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(S[i] == '+'){
                    st.push(a+b);
                }else if(S[i] == '*'){
                    st.push(a*b);
                }else if(S[i] == '-'){
                    st.push(b-a);
                }else{
                    st.push(b/a);
                }
            }
        }
        // at last i will return last element of stack
        return st.top();
    }
