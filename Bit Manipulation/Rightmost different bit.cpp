// Problem Link : https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?track=P100-Bit%20Magic&batchId=197#
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int ans = 1;
        // i will remove the last bit while they are same
        while((m > 0 || n > 0) && n%2 == m%2){
            m = m>>1;
            n = n>>1;
            ans++;
        }
        return ans;
    }
