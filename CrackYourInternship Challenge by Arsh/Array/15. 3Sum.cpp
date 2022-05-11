// Problem Link : https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int st = i+1, ed = nums.size()-1;
            while(st < ed){
                if(nums[i]+nums[st]+nums[ed] == 0){
                    vector<int> temp = {nums[i],nums[st],nums[ed]};
                    if(ans.empty() || ans.back() != temp)
                        ans.push_back({nums[i],nums[st],nums[ed]});
                    st++;
                }else if(nums[i]+nums[st]+nums[ed] < 0)
                    st++;
                else
                    ed--;
            }
        }
        return ans;
    }
};
