// Problem Link : https://leetcode.com/problems/top-k-frequent-elements/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // to store frequency of evert element
        
        for(int i = 0; i < nums.size(); i++){ // updating map
            mp[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < k; i++){ // we need ke frequent element so run this loop k times
            int mx = INT_MIN;
            int me;
            for(auto i : mp){ // finding largest frequent element
                if(i.second > mx){
                    me = i.first;
                    mx = i.second;
                }
            }
            mp.erase(me); // removing that element to get next largest element
            ans.push_back(me); // adding that in answer
        }
        return ans;
    }
