// Problem Link : https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1/?track=P100-Bit%20Magic&batchId=197#
    unsigned int swapBits(unsigned int n)
    {
    	unsigned int even = n; // i will store srt bits which are at even position
    	unsigned int odd = n; // i will store srt bits which are at odd position
    	int i = 0; // to tack track about position
    	while(n != 0){
    	    if(i%2 == 0){
    	        // if current position is even and here bit is set then i will unset this bit in odd number
    	        // so odd number will contain unset bits at even position
    	        if(n%2 == 1){
    	            odd ^= (1 << i);
    	        }
    	    }else{
    	        // if current position is odd and here bit is set then i will unset this bit in even number
    	        // so even number will contain unset bits at odd position
    	        if(n%2 == 1){
    	            even ^= (1 << i);
    	        }
    	    }
    	    i++;
    	    n /= 2;
    	}
    	// to swap the odd and even bits i will do left shift in even and right sift in odd by one
    	even = even<<1;
    	odd = odd>>1;
    	
    	// returning the answer
    	return (even|odd);
    }
