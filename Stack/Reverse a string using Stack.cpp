// Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#
char* reverse(char *S, int len)
{
    stack<char> st;
    // adding every char into stack
    for(int i = 0; i < len; i++){
        st.push(S[i]);
    }
    
    // removing everything from stack and storing into string to get reversed order
    for(int i = 0; i < len; i++){
        S[i] = st.top();
        st.pop();
    }
    return S;
}
