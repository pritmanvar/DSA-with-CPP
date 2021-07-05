// Problem Link : https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
    string smallestWindow (string s, string p)
    {
        // Your code here
        int str[256] = {0}; // to store frequancy of current window
        int pat[256] = {0}; // to store frequency of pattern
        
        // updating frequancy array for pattern
        for(int i = 0; i < p.length(); i++){
            pat[p[i]]++;
        }
        
        // to store number of matched char in current window
        int matched = 0;
        
        int len = INT_MAX; // length of current ans
        string ans = "";
        
        int i = 0; // ending point of current window
        int j = 0; // starting point of current window
        
        while(i < s.length()){
            if(matched < p.length()){ // if matched char in current window is less then pattern size then i will add more
                if(pat[s[i]] > str[s[i]]){ // if frequency of comming char is less then required then update matched
                    matched++;
                }
                str[s[i++]]++;
            }else{
                if(len > i-j){ // if length of current window is less then length of ans then i ll update ans and it's length 
                    len = i-j;
                    ans = s.substr(j,len);
                }
                if(pat[s[j]] >= str[s[j]]){ // if frequency of leaving char is less or equal to required then i ll update matched
                    matched--;
                }
                str[s[j++]]--;
            }
        }
        
        // if i can remove more char from front of the window
        while(matched == p.length()){
            if(len > i-j){
                len = i-j;
                ans = s.substr(j,len);
            }
            if(pat[s[j]] >= str[s[j]]){
                matched--;
            }
            str[s[j++]]--;
        }
        if(ans == "")
            return "-1";
        return ans;
    }
