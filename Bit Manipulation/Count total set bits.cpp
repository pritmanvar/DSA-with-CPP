// Problem Link : https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#

    // Approch : 
    // Decimal	E	D	C	B	A
        // 0	  0	0	0	0	0
        // 1	  0	0	0	0	1
        // 2	  0	0	0	1	0
        // 3	  0	0	0	1	1
        // 4	  0	0	1	0	0
        // 5	  0	0	1	0	1
        // 6	  0	0	1	1	0
        // 7	  0	0	1	1	1
        // 8	  0	1	0	0	0
        // 9	  0	1	0	0	1
        // 10 	0	1	0	1	0
        // 11	  0	1	0	1	1
        // 12	  0	1	1	0	0
        // 13	  0	1	1	0	1
        // 14	  0	1	1	1	0
        // 15	  0	1	1	1	1
        // 16	  1	0	0	0	0
    
    // here is a patern
    // Every alternate bits in A are set.
    // Every 2 alternate bits in B are set.
    // Every 4 alternate bits in C are set.
    // Every 8 alternate bits in D are set.
    // …..
    // This will keep on repeating for every power of 2.
    
    // for every position (A,B,C...) i will count number of complete groups above that number
    // and every comlete group has same number of set bits so i will add that in my count and after that i have to count set bit in last incomplete group
    int countSetBits(int n)
    {
        int count = 0;
        
        for(int i = 0; i < (int)log2(n)+1; i++){ // log2(n)+1 will give number of bits in number 'n';
            int group = n/pow(2,i+1); // This will give number of complete groups till now for ith bit from right
            count += pow(2,i)*group; // pow(2,i) is number of set bit in each complete group
            
            if(n&(1<<i)){ // if my ith bit is set then and only then there is a possibility that there might be set bits befor that
                // now i will find how many elements in incomplete group and afther that i will substract number of bits which are 0 so remaining will be one
                // my current bit is 1 means there must be pow(2,i) bits who is zero
                // this condition is to avoid floating point exception
                if(group > 0)
                    count += n%(group*(int)pow(2,i+1)) - pow(2,i);
                else
                    count += n - pow(2,i);
                    
                count++; // this is for current bit here current bit is set so i will increment count by 1
            }
        }
        return count;
    }
