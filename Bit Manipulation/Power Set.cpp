// Problem Link : https://practice.geeksforgeeks.org/problems/power-set4302/1#
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    
		    // set bit of every number will guide us that we have to take char at that possition or not
		    for(int i = 1; i < pow(2,s.length()); i++){
		        string str = "";
		        int tp = i;
		        int j = 0;
		        while(tp != 0){
		            if(tp%2 == 1){
		                str += s[j];
		            }
		            j++;
		            tp /= 2;
		        }
		        ans.push_back(str);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
