// Problem Link : https://leetcode.com/problems/subsets/
    vector<vector<int>> solve(vector<int> nums, int ind){
        // if we are at end of array then we will return a vector who will contain empty vector because empty set is subset of all set.
        if(ind == nums.size()){ 
            vector<vector<int>> ans;
            vector<int> empty;
            ans.push_back(empty); // adding empty set
            return ans;
        }
        
        // to recive collection of subsets which will return by next recursive call
        vector<vector<int>> recive;
        
        // every element has 2 choices
        // 1. it will present in subarray 
        // 2. it will not present in subarray 
        // recive will store subsets where current elements is not present
        // temp will store subsets where current element is present        
        vector<vector<int>> temp;
        
        recive = solve(nums,ind+1);
        temp = recive;
        
        for(int i = 0; i < temp.size(); i++){
            temp[i].push_back(nums[ind]); // adding current element in every subsets
        }
        recive.insert(recive.end(),temp.begin(),temp.end()); // adding temp into recive
        return recive; // returning recive
    }
    
    // Main function
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums,0);
    }
