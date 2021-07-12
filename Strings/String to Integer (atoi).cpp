// Problem Link : https://leetcode.com/problems/string-to-integer-atoi/
    int myAtoi(string s) {
        int i = 0;
        
        // removing leading whitespace
        while(i < s.length() && s[i] == ' ')
            i++;
        
        // if there is end of string then return 0
        if(i == s.length())
            return 0;
        
        // reading sign 
        // 1 == positive
        // -1 == negative
        int sign = 1;
        if(s[i] == '+' || s[i] == '-'){
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        
        long num = 0;

        while(i < s.length()){
            if(s[i] < '0' || s[i] > '9'){ // if char is not digit then we will return number till now
                return sign*num;
            }
            
            num = num*10 + s[i]-'0'; // updating the number
            
            // if cause overflow then return currosponding value with sign
            if(num > INT_MAX){
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            i++;
        }
        return sign*num;
    }
