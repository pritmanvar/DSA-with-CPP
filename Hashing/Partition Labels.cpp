// Problem Link : https://leetcode.com/problems/partition-labels/
    vector<int> partitionLabels(string s) {
        vector<int> ans; // in it we will store our answer
        
        int n = s.length();
        unordered_map<char,int> mp; // to store frequency of every char in the s who are not included in any part
        unordered_set<char> part; // to store which char are present in current part
        
        for(int i = 0; i < n; i++){ // updating mp
            mp[s[i]]++;
        }
        
        int len = 0; // length of current part
        
        for(int i = 0; i < n; i++){
            part.insert(s[i]); // adding comming char in the part
            mp[s[i]]--; // now this char is in the part so i will reduce frequency of current char by 1
            len++;
            
            bool is_valid = true; // to check that current part is valid or not
            
            // if frequency of every char who is present in part is zero then and only then current part is valid
            for(char j : part){
                if(mp[j] > 0){
                    is_valid = false;
                    break;
                }
            }
            
            // if current part is valid then add it's length in ans and clearing part and making len zero to start new part
            if(is_valid){
                ans.push_back(len);
                len = 0;
                part.clear();
            }
        }
        return ans;
    }
