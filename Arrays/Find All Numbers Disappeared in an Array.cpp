// Problem Link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i])-1] > 0) // we will go to the position at nums[i] and make that negative to mark that element is present which value is equal to this position
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){ // this element is positive means that element is not present whose value is equal to this position
                ans.push_back(i+1);
            }
        }
        return ans;
        // we can use this method because we know that element will be in range of 1 to nums.size()
    }
