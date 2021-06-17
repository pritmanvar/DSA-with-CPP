// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/submissions/
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 1; i < n; i++){ 
            nums[i] += nums[i-1];
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] == k){ 
                ans++;
            }
            if(mp.count(nums[i]-k) > 0){
                ans += mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
