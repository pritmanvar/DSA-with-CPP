// Problem Link : https://leetcode.com/problems/find-the-duplicate-number/solution/
    int findDuplicate(vector<int>& nums) {
        // Sorted an array
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){//If two concutive elements are same then return that beccause they are same
                return nums[i];
            }
        }
        return 0;
    }