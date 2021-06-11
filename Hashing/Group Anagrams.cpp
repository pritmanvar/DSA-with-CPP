// Problem Link : https://leetcode.com/problems/group-anagrams/
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
    
        for(int i = 0; i < str.size(); i++){      
            string key = str[i];
            // if 2 sorted strings are same then they are anagrams so we will sort the string and consider that as key for the map
            sort(key.begin(),key.end());
            mp[key].push_back(str[i]);
        }
        // adding all keys from map to ans.
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
