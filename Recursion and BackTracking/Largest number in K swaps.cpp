// Problem Link : https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
    string solve(string str, int i, int k){
        if(k == 0 || i == str.length()){ // base case
            return str;
        }
        
        int mx = i; // to store index of max char in the remaining string
        string temp; // to store ans returned by next call
        string ans; // to store max ans of all which are returned by calls.
        
        for(int j = i; j < str.length(); j++){// finding max
            if(str[mx] <= str[j]){
                mx = j;
            }
        }
        
        if(str[mx] == str[i]){ // if current element is same as max then we will skip that
            return solve(str,i+1,k);
        }else{
            for(int j = i+1; j < str.length(); j++){ // we will try to swap it with all elements which are equal to max
                if(str[j] == str[mx]){
                    swap(str[i],str[j]); // swapping to get the maximum digit at required index.
                    temp = solve(str,i+1,k-1);
                    ans = max(ans,temp);
                    swap(str[i],str[j]); // BackTracking
                }
            }
        }
        return ans;
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       return solve(str,0,k);
    }
