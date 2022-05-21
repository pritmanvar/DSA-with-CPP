// Probelm Link : https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int k = j+1, l = nums.size()-1;
                int reqSum = target - nums[i] - nums[j];
                
                while(k < l){
                    if(nums[k] + nums[l] == reqSum){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                    }else if(nums[k] + nums[l] < reqSum)
                        k++;
                    else
                        l--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(int i = ans.size()-2; i >= 0; i--){
            if(ans[i] == ans[i+1])
                ans.erase(ans.begin()+i);
        }
        return ans;
    }
};
