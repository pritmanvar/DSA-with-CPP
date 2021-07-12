// Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int count = 0;
        while(b > 0){
            // if both are different then increment the count
            if((a&1) != (b&1)){
                count++;
            }
            a = a>>1;
            b = b>>1;
        }
        // now b is 0 we we have to flip all set bits in a
        while(a != 0){
            if((a&1) == 1)
                count++;
            a = a>>1;
        }
        return count;
    }
