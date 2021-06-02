    // Problem Link : https://leetcode.com/problems/count-and-say/
    // This problem is solved by recursion
    string countAndSay(int n) {
        // Base case
        if(n == 1){
            return "1";
        }
        string ans = countAndSay(n-1);//answer for the previous element
        string new_ans = "";
        int count = 1;
        
        //calculating answer for the new element by the use of previous answer
        for(int i = 1; i < ans.length(); i++){
            if(ans[i-1] == ans[i]){
                count++;
            }else{
                new_ans += to_string(count) + ans[i-1];
                count = 1;
            }
        }
        new_ans += to_string(count) + ans[ans.length() - 1];
        return new_ans;
    }