// Problem Link : https://leetcode.com/problems/decode-string/
    string decodeString(string s) {
        string ans = ""; // to store answer.
        
        for(int i = 0; i < s.length(); i++){
            // if current char is lowercase letter then i will simply add that into the answer.
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
                continue;
            }
            
            // in this loop i will collect number.
            int num = 0;
            while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                num = num*10+s[i]-'0';
                i++;
            }
            // in this i will collect the string between ballanced square brackets.
            string rans = "";
            if(s[i] == '['){
                int open = 1;
                i++;

                string rec = "";
                // i will run this loop till number of opening and closing brackets are not same from ith char.
                while(open > 0){
                    rec += s[i];
                    if(s[i] == '[')
                        open++;
                    else if(s[i] == ']')
                        open--;
                    i++;
                }
                // call same function recursively for the string rec
                // here I am excluding last char because it will be ']'.
                rans = decodeString(rec.substr(0,rec.length()-1));
            }
            // add answer of recursion num times into ans.
            for(int j = 0; j < num; j++){
                ans += rans;
            }
            i--;
        }
        return ans;
    }
