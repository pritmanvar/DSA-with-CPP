// Problem Link : https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src)
{     
    //Your code here 
    string ans = "";
    int n = src.length();
    
    int i = 0;
    while(i < n){
        int count = 1;
        while(i+1 < n && src[i] == src[i+1]){
            i++;
            count++;
        }
        ans += src[i] + to_string(count);
        i++;
    }
    return ans;
}    
