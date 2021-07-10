// Problem Link : https://codeforces.com/contest/1547/problem/B

#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        string str;
        cin >> str;
 
        string temp = "";
 
        int ind = -1;
        // first of all we will searach for 'a'
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'a'){
                ind = i;
                break;
            }
        }
        // if 'a' is not present then we will print no and continue to next test case
        if(ind == -1){
            cout << "NO\n";
            continue;
        }
        
        // here we will try to findout other chars who follows the rule
        int len = 1; // 'a' is present so current length is 1
        char ch = 'b'; // we will start searching for 'b' because 'a' is already present
        // 'a' is at index ind so next char can be at index ind-1 or ind+1
        int st = ind-1;
        int ed = ind+1;
        bool check = true;
      
        // when len becomes str.length whole string is processed
        while(len != str.length()){
            // if end is as same as ch
            if(ed < str.length() && str[ed] == ch){
                ch++;
                ed++;
                len++;
            }else if(st >= 0 && str[st] == ch){ // if start is as same as ch
                ch++;
                st--;
                len++;
            }else{ // if none of st or ed is same as ch means here rule is breaking so we will mark check as false and break the loop
                check = false;
                break;
            }
        }
  
        // check is false means rule was breaking.
        if(check){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
