// Problem Link : https://leetcode.com/problems/longest-common-prefix/
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        if(strs.size() == 1)
            return strs[0];
        
        // traverse through 1st string while matching ith char in every string
        for(int i = 0; i <  strs[0].length(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(i == strs[j].length() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
