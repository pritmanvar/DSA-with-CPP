// Problem Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
    
    // function to check that current window and p is anagram or not
    bool isAnagram(int pattern[],int window[]){
        for(int i = 0; i < 26; i++){
            if(pattern[i] != window[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length() > s.length()) // special case
            return ans;
        
        int pattern[26] = {0};
        int window[26] = {0};
        
        for(int i = 0; i < p.length(); i++){ // updating hash for p
            pattern[p[i]-'a']++;
        }
        
        int end = 0;
        int start = 0;
        
        for(end = 0; end < p.length(); end++){ // updating hash for first window
            window[s[end]-'a']++;
        }
        
        // we will traverse every window
        while(end < s.length()){
            // if both are anagram then add starting point to ans and move to next window
            if(isAnagram(pattern,window)){
                ans.push_back(start);
            }
            window[s[start++]-'a']--;
            window[s[end++]-'a']++;
        }
        // last window will be not consider in while loop so checking fot that here 
        if(isAnagram(pattern,window))
            ans.push_back(start);
        
        return ans;
    }
