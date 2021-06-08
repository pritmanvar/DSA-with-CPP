// Problem Link : https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
	int lps(string s)
	{
	    // Your code goes here
	    int lps[s.length()] = {0};
	    int len = 0;
	    int i = 1;
	    while(i < s.length()){
	        // tring to extend previous prefix
	        if(s[len] == s[i]){
	            len++;
	            lps[i] = len;
	            i++;
	        }else{
	            // we can't extend previous prefix and lenght of previous prefix is 0 then lenght of current prefix will also 0
	            if(len == 0){
	                lps[i] = 0;
	                i++;
	            }else{
	                // we will try to extend previous of previous prefix
	                len = lps[len - 1];
	            }
	        }
	    }
	    return lp[s.length()-1];
	}
