// Problem Link : https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
    // applied  Moore’s Voting Algorithm
    int majorityElement(int a[], int size)
    {
        int ans = a[0]; 
        int freq = 1; 
        
        
        for(int i = 1; i < size; i++){
            if(a[i] != ans){
                freq--;
            }else{
                freq++;
            }
            if(freq < 0){
                freq = 1;
                ans = a[i];
            }
        }
        freq = 0;
        for(int i = 0; i < size; i++){
            if(a[i] == ans)
                freq++;
        }
        return freq > size/2 ? ans : -1;
    }
