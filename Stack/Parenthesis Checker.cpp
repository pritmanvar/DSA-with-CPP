// Problem Link : https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i = 0; i < x.length(); i++){
            // if brackets is opening then push it into stack
            if(x[i] == '{' || x[i] == '(' || x[i] == '['){
                st.push(x[i]);
            }else{
                // if bracket is closing and size is 0 then it is not valid
                if(st.size() == 0){
                    return false;
                }
                char ch = x[i];
                // If brackets are dismatching then also they are not valid
                if(ch == '}' && st.top() != '{'){
                    return false;
                }else if(ch == ']' && st.top() != '['){
                    return false;
                }else if(ch == ')' && st.top() != '('){
                    return false;
                }
                // If brackets are matching then also they are valid so i will pop it to mark is as processed
                st.pop();
            }
        }
        // if after processing of all brackets there is any unprocessed bracket in stack then it is not valid
        if(st.size() == 0){
            return true;
        }else{
            return false;
        }
    }
