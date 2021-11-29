// Problem Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Better Opproch : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/716453/C%2B%2B-O(n)-solution-with-2-pointer-approach-or-95-in-memory

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0; // To store answer
        unordered_map<char,int> mp; // to store frequency of elements in the window.
        int i = 0,j = 0;
        int last = 0; // it will store starting index of last window which is valid.
        
        while(j < s.length()){
            if(mp['a'] && mp['b'] && mp['c']){ // window is valid from i to j-1
                last = i; 
                ans++; // update answer
                
                // minimize the window.
                while(mp['a'] && mp['b'] && mp['c']){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                
                // I can expand the current window till the end of string and starting of previous window
                // so in that substring every substring who contain current window is also valid 
                // so by this equation i will consider that.
                
                /*
                    if string is "ababcbc" and current window is for "abc"
                    then j = 5, last = 0 (because it is 1st valid window), i = 3
                    (s.length()-j) will include "abcb","abcbc"
                    (i-last-1) will include "babc","ababc"
                    (s.length()-j)*(i-last-1) will include "babcb","ababcb","babcbc","ababcbc"
                    
                    so 8 strings by this equation and another 1 string "abc" by line no. 14
                */
                ans += (s.length()-j) + (i-last-1) + (s.length()-j)*(i-last-1);
            }else{ // unvalid window so expand it
                mp[s[j]]++;
                j++;
            }
        }
        // I haven't consider last char so considiring that here
        if(mp['a'] && mp['b'] && mp['c']){
            last = i;
            ans++;
            while(mp['a'] && mp['b'] && mp['c']){
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            ans += (s.length()-j) + (i-last-1) + (s.length()-j)*(i-last-1);
        }
        return ans;
    }
};
