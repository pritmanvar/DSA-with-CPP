// Problem Link : https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    // It will return sum of 2 strings.
    string sum(string& num1, string& num2){
        string ans = "";
        int carry = 0;
        
        int i = num1.length()-1, j = num2.length()-1;
        
        while(i >= 0 || j >= 0 || carry > 0){
            int sum = carry;
            if(i >= 0)
                sum += num1[i--]-'0';
            if(j >= 0)
                sum += num2[j--]-'0';
            
            carry = sum/10;
            sum = sum%10;
            ans = to_string(sum)+ans;
        }
        return ans;
    }
    
    // To multiply 2 strings.
    string multiply(string num1, string num2) {
        // if one of them is 0 the answer will be 0.
        if(num1 == "0" || num2 == "0")
            return "0";
        
        
        string ans = "";
        
        for(int i = 0; i < num2.length(); i++){
            string mul = "";
            // it will multiply the one digit of num2 with num1
            for(int j = 0; j < num2.length()-i-1; j++)
                mul += "0";
            
            int carry = 0, m = 1;
            for(int j = num1.length()-1; j >= 0; j--){
                m = (num2[i]-'0')*(num1[j]-'0') + carry;
                carry = m/10;
                mul = to_string(m%10) + mul;
            }
            
            // submition of ans and mul
            if(carry > 0)
                mul = to_string(carry) + mul;
            if(ans == "")
                ans = mul;
            else
                ans = sum(ans,mul);
        }
        
        return ans;
    }
};
