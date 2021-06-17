// Problem Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
	    vector<string>solve(string str,int i,int len){
	        // len = length of string
	        // i = elements befor i will be fixed we can't change their order. so we will find permutations for the elements which are after i
	        
	        // i is at last element then we can get only 1 permutation with 1 char
	        // so we will return that
	        if(i == len-1){ 
	            vector<string> a;
	            a.push_back(str);
	            return a;
	        }
	        
	        vector<string> ans;
	        // in this loop we will swap every element after i with element at i to get different permutations
	        for(int j = i; j < len; j++){
	            vector<string> temp;
	            
	            swap(str[i],str[j]);
	            temp = solve(str,i+1,len);
	            ans.insert(ans.end(),temp.begin(),temp.end()); // adding all permutaions in the ans which are recived by recursion call
	            swap(str[i],str[j]);// again swaping to get original string for the next itration. backtrack
	        }
	        return ans;
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> str = solve(S,0,S.length());
		    sort(str.begin(),str.end()); // sorting ans to get desired order
		    return str;
		}
