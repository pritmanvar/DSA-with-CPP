// Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0; // to store answer
        int freq[26] = {0}; // will store frequency of every element in window
        int same_char = 0; // will store maximum number of same char in window
        int l = 0, r = 0;
        
        /*
            If window length - same_char is less or equal to k
            then we can change k different chars 
            so it is valid window.
        */
        while(r < s.length()){
            // considering window of l to r-1 and if it is valid
            if(r-l-same_char <= k){
                ans = max(r-l,ans); // update answer
                
                // preparation for next window. here upcomming char is rth char.
                freq[s[r]-'A']++; // update it's frequency
                same_char = max(same_char,freq[s[r]-'A']); // update same_char
                r++;
            }else{ // current window is invalid. here we will remove starting element of window
                freq[s[l]-'A']--; // update frequency
                l++;
                
                // for finding next maximum number of same char
                int temp = 0;
                for(int i = 0; i < 26; i++)
                    temp = max(temp,freq[i]);
                same_char = temp;
            }
        }
        // i haven't considered last char so here i am considering that
        if(r-l-same_char <= k)
            ans = max(r-l,ans);
        return ans;
    }
};
