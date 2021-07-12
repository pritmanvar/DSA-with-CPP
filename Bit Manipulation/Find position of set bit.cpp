// Problem Link : https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
    int findPosition(int N) {
        if(N == 0)
            return -1;
        
        // if number is in power of 2 then and only then it has only 1 set bit
        if((N&(N-1)) == 0){
            return log2(N)+1;
        }
        return -1;
    }
