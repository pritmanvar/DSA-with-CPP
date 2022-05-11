// Problem Link : https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(target-nums[i]) > 0){
                vector<int> ans;
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }else{
                mp[nums[i]] = i;
            }
        }
        return nums;
    }
};
