// Problem Link : https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
	int lps(string s)
	{
	    // Your code goes here
	    int lps[s.length()] = {0};
	    int len = 0;
	    int i = 1;
	    while(i < s.length()){
	        if(s[len] == s[i]){
	            len++;
	            lps[i] = len;
	            i++;
	        }else{
	            if(len == 0){
	                lps[i] = 0;
	                i++;
	            }else{
	                len = lps[len - 1];
	            }
	        }
	    }
	    return lp[s.length()-1];
	}