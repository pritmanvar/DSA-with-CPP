// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays-ii/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        // add every element in nums1 to the map
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++){
            // if current element is present nums1 then add that in ans and decrease its frequency from map
            if(mp[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }
