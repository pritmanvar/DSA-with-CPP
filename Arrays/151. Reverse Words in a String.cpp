// Problem Link : https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        int st = 0;
        
        // remove extra space from begining.
        while(st < s.length() && s[st] == ' ')
            st++;
        
        
        int ed = st;
        string ans = "";
        for(int i = st; i < s.length(); i++){
            // if it is end of string or next char is space then it is end of word.
            if(i == s.length()-1 || s[i+1] == ' '){
                if(s[i] == ' '){ // if current and next char is space then skip a space.
                    st++;
                    ed++;
                    continue;
                }
                // add new word in the answer.
                
                // in first word i will not add space in the ans
                if(ans == "")
                    ans = s.substr(st,ed-st+1) + ans;
                else
                    ans = s.substr(st,ed-st+1) + " " + ans;
                st = i+2;
            }
            ed++;
        }
        return ans;
    }
};
