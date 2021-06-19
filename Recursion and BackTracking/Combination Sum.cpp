// Problem Link : https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
    vector<vector<int>> solve(vector<int> arr, int sum, int indx, vector<int> comb){
        // arr : stores the numbers which we have to use in our combinaations
        // sum : for which we have to find combination
        // indx : we can't use elements before this indx in our further combinations. i used this to avoid same combinations.
        // comb : stores 1 combination we had made till now
        
        
        // If sum is 0 then we will return that combination as answer
        if(sum == 0){
            vector<vector<int>> ans;
            ans.push_back(comb);
            return ans;
        }
        
        vector<vector<int>> combinations;//To store possible combinations which will returned by next some recursive calls
        for(int i = indx; i < arr.size(); i++){// using elements after indx to make our next combination
            if(sum - arr[i] >= 0){// if this element is safe then we will call the solve finction
                vector<vector<int>> temp;// temporary array to store combination returned by the next call
                comb.push_back(arr[i]);// adding this element in the combination till now
                temp = solve(arr,sum-arr[i],i,comb);
                combinations.insert(combinations.end(),temp.begin(),temp.end());// adding returned combination to the our main output of this recursive call
                comb.pop_back();// BackTracking. remobing this element from combination till now
            }
        }
        return combinations; // returning combinations
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int> comb; // to store one possible combination
        sort(A.begin(),A.end()); // sort the array to get answer in desired order
        A.erase(unique(A.begin(),A.end()),A.end());// removing dublicates to avoid same combinations
        return solve(A,B,0,comb);// calling function call
    }
