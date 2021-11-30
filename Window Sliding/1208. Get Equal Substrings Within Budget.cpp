// Problem Link : https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int i = 0, j = 0;
        
        while(j < s.length()){
            maxCost -= abs(s[j]-t[j]); // update cost to match current char
            
            // while remaining cost is negative remove elements from starting of window
            while(maxCost < 0){
                maxCost += abs(s[i]-t[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
