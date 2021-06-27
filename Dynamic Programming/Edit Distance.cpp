// Problem Link : https://practice.geeksforgeeks.org/problems/edit-distance3702/1
    int editDistance(string s, string t) {
        int m = s.length(); // for the string s
        int n = t.length(); // for the string t
        
        // dp array where row will represent strint t and coloumns will represent string t
        int arr[n+1][m+1];
        // base case in recursion
        // if we consider sting s as empty and wants to match it with i char of string t then required operation would be i
        for(int i = 0; i < n+1; i++){ 
            arr[i][0] = i;
        }
        // if we consider sting t as empty and wants to match it with i char of string s then required operation would be i
        for(int i = 0; i < m+1; i++){
            arr[0][i] = i;
        }
        
        // in each iteration we will consider first i char of string t and first j char of string s and stores minimum operation at that index
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                // if last char of both string matches then we will remove last char from both string that and minimum operation for that string will be required operation for remaining string after removing last char
                if(t[i-1] == s[j-1]){
                    arr[i][j] = arr[i-1][j-1];
                }else{
                    // store minimum of 3 operatons
                    // [i-1][j] == inserting element in string s
                    // [i-1][j-1] == replacin element in string s
                    // [i][j-1] == removing element in string s
                    // +1 for the operation which are doing in the above operations
                    arr[i][j] = 1+min(arr[i-1][j], min(arr[i-1][j-1],arr[i][j-1]));
                }
            }
        }
        // returning answer
        return arr[n][m];
    }
