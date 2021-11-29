// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char,int> freq_s;
        unordered_map<char,int> freq_p;
        
        // Update frequency of string s
        for(int i = 0; i < s.length(); i++){
            freq_s[s[i]]++;
        }
        
        string p = ""; // string which we need to replace
        // create string p
        for(auto i : freq_s){
            int count = i.second - n/4;
            for(int j = 0; j < count; j++){
                p += i.first;
                freq_p[i.first]++;
            }
        }
        
        // base case
        if(p == "")
            return 0;
        
        // clear frequency map for string s.
        freq_s.clear();
        
        // Algorithm to find minimum length of substring which contains string p.
        int i = 0, j = 0;
        int len = s.length();
        int matched = 0; // number of matched char in current window with string p
        
        while(j < n){
            if(matched < p.length()){ // current window doesn't contain string p
                if(freq_s[s[j]] < freq_p[s[j]]){ // expand widnow
                    matched++;
                }
                freq_s[s[j]]++;
                j++;
            }else{ // current window contain string p
                len = min(len,j-i); // update length
                // remove starting char
                freq_s[s[i]]--;
                if(freq_p[s[i]] > freq_s[s[i]]){
                    matched--;
                }                
                i++;
            }
        }
        
        // if i can remove more char from front of the window
        while(matched >= p.length()){
            len = min(len,j-i);
            freq_s[s[i]]--;
            if(freq_p[s[i]] > freq_s[s[i]]){
                matched--;
            }
            i++;
        }
        return len;
    }
};
