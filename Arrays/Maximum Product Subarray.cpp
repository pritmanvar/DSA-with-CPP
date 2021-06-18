// Problem Link : https://leetcode.com/problems/maximum-product-subarray/
    int maxProduct(vector<int> nums) {
        int n = nums.size();
        
        int i = 0;
        int maxp = nums[0]; // stored max product
        while(i < n){
            if(nums[i] == 0){ // if current element is zero and our max is less than zero then make it zero and continue
                maxp = maxp < 0? 0 : maxp;
                i++;
                continue;
            }
            
            bool check1 = true; // to fund profuct of 1st negative number
            bool one = false; // to check that 1 is present or not
            int count = 0; // to count the number of negative numbers
            int prd = 1; // to store product
            int prd1; // to store product of elements till 1st negative element
            int prd2 = 1; // to store product of elements till last negative element to the end
            while(i < n && nums[i] != 0){// if element is 0 then we will break the loop because we can't consider a subarray which has 0 in the middle because it will make product 0
                // calculating product
                prd *= nums[i]; 
                prd2 *= nums[i];
                
                if(nums[i] < 0){
                    prd2 = nums[i]; // with help of this step we will able to calculate product of elements till last negative element to the end
                    count++;// updating count
                    
                    if(check1){ // if it is 1st negative element then we will store product
                        check1 = false;
                        prd1 = prd;
                    }
                }
                if(nums[i] == 1)
                    one = true; // this true makes sure that one is present
                i++;
            }
            
            if(count%2 == 0){ // if number of negative integers is even then we will consider all subarray as a possibility 
                maxp = max(maxp,prd);
            }else{
                if(prd1 != prd && prd != prd2){
                    maxp = max(maxp,max(prd/prd1,prd/prd2)); // we will remove subarray till 1st negative element or last negative element to the end to make product positive
                }
                // one of then is same as product then we will apply upper logic for different one
                else if(prd == prd1 && prd != prd2){ 
                    maxp = max(maxp,max(prd,prd/prd2));
                }else if(prd != prd1 && prd == prd2){
                    maxp = max(maxp,max(prd/prd1,prd));
                }else{ 
                    if(one) // if both are same and one is present in subarray then we will compare max with one
                        maxp = max(maxp,1);
                    else // if both are same and one is not present in subarray then we will compare max with product. in this case product will be negative because here number of negative elements is odd.
                        maxp = max(maxp,prd);
                }
            }
        }
        return maxp;
    }
