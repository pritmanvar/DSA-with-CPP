// Problem Link : https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#
    bool solve(string str1, int i, string str2, int j){
        if(i == str1.length() && j == str2.length()){// if both are at the end then return true
            return true;
        }
        
        // if both are same then calling for next char or special case when we skip 1 char from pattern
        if(str1[i] == str2[j] || str1[i] == '?'){
            return solve(str1,i+1,str2,j+1);
        }
        
        if(str1[i] == '*'){// special case
            int indx = j;
            // skiping every possibility from pattern and in one of then returns true then we will return true
            while(indx <= str2.length()){
                if(solve(str1, i+1,str2, indx)){
                    return true;
                }
                indx++;
            }
        }
        return false;
    }
    bool match(string wild, string pattern)
    {
        return solve(wild,0,pattern,0);
    }
