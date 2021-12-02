// Problem Link : https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) // if current element is greater than 0 then we can't get desired tupple.
                break;
            if(i > 0 && nums[i] == nums[i-1]) // to avoid duplicates
                continue;
            
            // two pointer approch
            int st = i+1, ed = nums.size()-1;
            while(st < ed){
                if(nums[i]+nums[st]+nums[ed] == 0){ // it is desired tupple
                    vector<int> temp = {nums[i],nums[st],nums[ed]};
                    if(ans.empty() || ans.back() != temp) // if same tupple is not present then insert this
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
