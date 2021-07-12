// Problem Link : https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#
    vector<int> singleNumber(vector<int> nums) 
    {
        int xr = 0; // after the loop this will contain xor of 2 elements who occurs odd time
        for(int i = 0; i < nums.size(); i++){
            xr ^= nums[i];
        }
        
        // this experession will give the number which will contain only one set bit at the possition at the rightmost set bit in xr
        int n = xr&(~(xr-1));
        
        int n1 = 0, n2 = 0;
        
        for(int i = 0; i < nums.size(); i++){
            // if this num contain set bit as same possion then it will go in 1 group other wise in another group
            // because right most bit in xr is set meanse of of num has this bit as set and onther has it as unset
            if((nums[i]&n) != 0){
                n1 ^= nums[i];
            }else{
                n2 ^= nums[i];
            }
        }
        // to maintain order of output
        if(n1 > n2)
            swap(n1,n2);
            
        return {n1,n2};
    }
