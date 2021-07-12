// Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    
    vector<string> ans; // global variable
    // ind == index for digits from which we will select a char
    // curr == combination till now
    void solve(string digits, int ind, unordered_map<char,string> mp, string curr){
        // if we are at the end of string then add curr in ans as a possible combination and return
        if(ind == digits.length()){
            if(curr.length() > 0)
                ans.push_back(curr);
            return;
        }
        
        string str = mp[digits[ind]]; // we will take a single char from the string which can be access by the digits[ind]
        
        for(int i = 0; i < str.length(); i++){ // one by one we will call every char from str and call for next ind in digits
            solve(digits, ind+1, mp, curr+str[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear(); // clearing previous answer
        
        // adding all keys into the map
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(digits,0,mp,""); // calling solve function that will fill the ans vector
        return ans;
    }
