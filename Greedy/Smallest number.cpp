// Problem Link : https://practice.geeksforgeeks.org/problems/smallest-number5829/1#
    string smallestNumber(int S, int D){
        string ans = ""; // to store answer.
        
        for(int i = 1; i <= D; i++){
            int j = i == 1? 1 : 0; // if i am setting 1st digit then that will start from 1
            while(9*(D-i) < S-j){ // i can't set next digit if i select j as current one then i will increment j by 1
                j++;
            }
            if(j > 9) // if my digit is greater than 9 then it is not possibal to get sum in given digits.
                return "-1";
            S -= j; // substract j from sum S
            ans += to_string(j); // append j from string.
        }
        return ans; 
    }
