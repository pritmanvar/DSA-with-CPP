// Problem Link : https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1
int minFlips (string S)
{
    // There are 2 possibilites
    // 1. String starts from 0
    // 2. String starts from 1
    // we will check both and return minimum of them
    char first = S[0];
    int ans1 = 0;
    int ans2 = 0;
    
    for(int i = 0; i < S.length(); i++){
        if(i%2 == 0 && S[i] == '1'){
            ans1++;
        }else if(i%2 == 1 && S[i] == '0'){
            ans1++;
        }
    }
    for(int i = 0; i < S.length(); i++){
        if(i%2 == 0 && S[i] == '0'){
            ans2++;
        }else if(i%2 == 1 && S[i] == '1'){
            ans2++;
        }
    }
    return min(ans1,ans2);
}
