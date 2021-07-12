// Problem Link : https://practice.geeksforgeeks.org/problems/set-bits0143/1#
    int setBits(int N) {
        int count = 0;
        while(N > 0){
            N = N&(N-1); // this step will unset the right most set bit. so we will count how many times we need to unset the bit
            count++;
        }
        return count;
    }
