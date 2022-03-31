// Problem Link : https://leetcode.com/problems/maximum-value-after-insertion/

class Solution {
public:
    string maxValue(string s, int x) {
        int len = s.length();
        int freq[10] = {0};
        while(x > 0){
            freq[x%10]++;
            x /= 10;
        }
        
        string ans = "";
        if(s[0] == '-'){
            ans += '-';
            int j = 0;
            for(int i = 1; i < len; i++){
                if(j == 10)
                    break;
                
                while(j < s[i]-'0'){
                    string temp = "";
                    while(freq[j] > 0){
                        temp += j+'0';
                        freq[j]--;
                    }
                    ans += temp;
                    j++;
                }
                ans += s[i];
            }
            
            while(j < 10){
                string temp = "";
                while(freq[j] > 0){
                    temp += j+'0';
                    freq[j]--;
                }
                ans += temp;
                j++;
            }
        }else{
            int j = 9;
            for(int i = 0; i < len; i++){
                if(j == -1)
                    break;
                
                while(j > s[i]-'0'){
                    string temp = "";
                    while(freq[j] > 0){
                        temp += j+'0';
                        freq[j]--;
                    }
                    ans += temp;
                    j--;
                }
                ans += s[i];
            }
            while(j >= 0){
                string temp = "";
                while(freq[j] > 0){
                    temp += j+'0';
                    freq[j]--;
                }
                ans += temp;
                j--;
            }
        }
        
        return ans;
    }
};
