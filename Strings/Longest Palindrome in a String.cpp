//Problem Link : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
    //Here is 2 possibilities.
    // 1 is that max lenth of palindrome string is odd
    // 2 is that max lenth of palindrome string is even
    string longestPalin (string S) {
        int mlen_odd = 1;
        int start_odd = 0;
        
        // In this loop we will consider each character as middle character in the palindromic string.
        // and try to expand that and note the max len and starting point of the string which has max len.
        for(int i = 1; i < S.length()-1; i++){
            int start = i-1;
            int end = i+1;
            int len_odd  = 1;
            
            while(start >= 0 && end < S.length() && S[start] == S[end]){
                len_odd += 2;
                start--;
                end++;
            }
            if(mlen_odd < len_odd){
                mlen_odd = len_odd;
                start_odd = start+1;
            }
            len_odd = 1;
        }
        
        int mlen_even = 0;
        int start_even;
        // In this loop we will consider 2 consecutive character as middle characters in the palindromic string.
        // and try to expand that and note the max len and starting point of the string which has max len.
        for(int i = 0; i < S.length() - 1; i++){
            if(S[i] == S[i+1]){
                int start = i;
                int end = i+1;
                int len_even = 0;
                
                while(start >= 0 && end < S.length() && S[start] == S[end]){
                    len_even += 2;
                    start--;
                    end++;
                }
                if(mlen_even < len_even){
                    mlen_even = len_even;
                    start_even = start+1;
                }
            }
        }
        // returns the string which has max length.
        if(mlen_even > mlen_odd){
            return S.substr(start_even,mlen_even);
        }else if(mlen_even < mlen_odd){
            return S.substr(start_odd,mlen_odd);
        }
    }