// Problem Link : https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0; // to store answer
        int zeros = 0; // number of zeros present in the current window
        int i = 0,j = 0; // to traverses nums
        
        while(j < nums.size()){
            if(zeros <= k){ // if in current window zeros is less than k then we can flip all so it is valid window
                ans = max(ans,j-i); // update answer, here i am taking length of i to j-1 because j is just comming it is not in previous window.
                if(nums[j] == 0) // upcomming element is zero
                    zeros++;
                j++;
            }else{ // if window has more than k zeros
                if(nums[i] == 0)
                    zeros--;
                i++;
            }
        }
        if(zeros <= k) // i have not considered last char in while loop
            ans = max(ans,j-i);
        return ans;
    }
};
