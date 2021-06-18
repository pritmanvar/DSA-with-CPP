// Problem Link : https://leetcode.com/problems/move-zeroes/submissions/
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && nums[i] != 0){ // finding the index of 1st zero
            i++;
        }
        int j = i;
        while(j < nums.size()){
            if(nums[j] != 0){ // if element is non zero then we will swap then with 1st zero 
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
