// Problem Link : https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], count = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(ans == nums[i])
                count++;
            else
                count--;
            
            if(count < 0){
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};
