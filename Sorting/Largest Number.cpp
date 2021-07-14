// Problem Link : https://leetcode.com/problems/largest-number/
    
    // comparator function in which combination gives bigger number
    static bool comp(int i, int j){
        
        string str1 = to_string(i);
        string str2 = to_string(j);
        
        return (str1+str2) > (str2+str1);
    }
    
    string largestNumber(vector<int>& nums) {
        
        // sorting array according to comparator
        sort(nums.begin(),nums.end(),comp);
        
        if(nums[0] == 0) // if largest number in array is 0 then all numbers will be 0
            return "0";
        
        string ans = "";
        for(int i = 0; i < nums.size(); i++){ // to add all elements in string
            ans += to_string(nums[i]);
        }
        
        return ans;
    }
