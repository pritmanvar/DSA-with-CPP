// Problem Link : https://leetcode.com/problems/remove-invalid-parentheses/
    
    // this function will check that current parentheses are valid or not.
    bool isValid(string str){
        stack<char> st;
        
        int i = 0;
        while(i < str.length()){
            if(str[i] == '('){
                st.push(str[i]);
            }else if(str[i] ==')'){
                // if current one is closing parenthes and stack is empty or there is another closing parenthes on the top then this is not valid.
                if(st.empty() == false && st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        return st.empty(); // if stack is not empty then it is not a valid parentheses.
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        // if given string is already valid then i will return that.
        if(isValid(s))
            return {s};
        
        // queue for BFS.
        queue<string> q;
        
        vector<string> ans; // to store answer.
        
        // BFS
        q.push(s);        
        while(q.size() > 0){
            int count = q.size();
            unordered_set<string> st; // set to avoid duplicates.
            bool got = false; // to check that have i any valid parenthes or not.
            
            for(int i = 0; i < count; i++){
                string str = q.front();
                q.pop();
                
                // traverse through whole string and in each interation i will remove jth char from string.
                for(int j = 0; j < str.length(); j++){
                    // if current char is same as previous char then after removing this i will get same string as i got after removing previous char so i will not so this again.
                    // if current char is not a parentheses then there is not any need to remove that.
                    // in both case i will skip current iteration.
                    if((j > 0 && str[j] == str[j-1]) || (str[j] != '(' && str[j] != ')')){
                        continue;
                    }
                    // remove current char and check it is valid or not and if valid then mark got as true.
                    string new_str = str.substr(0,j)+str.substr(j+1,str.length()-j-1); 
                    bool valid = isValid(new_str);
                    if(valid){
                        got = true;
                    }
                    // if current string is not appeared before then add that into queue and set.
                    if(st.count(new_str) == 0){
                        // if current string is valid then add that into ans
                        if(valid)
                            ans.push_back(new_str);
                        q.push(new_str);
                        st.insert(new_str);
                    }
                }
            }
            // if i got the answer then return that
            if(got == true)
                return ans;
        }
        return {""}; // if didn't get answer then return vector with empty string.
    }
