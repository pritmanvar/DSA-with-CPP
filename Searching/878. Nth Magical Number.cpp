// Problem Link : https://leetcode.com/problems/nth-magical-number/
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = (long long)min(a,b), h = (long long)n*min(a,b); // search space of binary search
        long long lcm = (long long)a*b/__gcd(a,b);
        
        while(l <= h){
            long long m = l + (h-l)/2;
            
            int magic_numbers = m/a + m/b - m/lcm; // number of magical number from 1 to m.
            
            // binary search algo on numbers
            if(magic_numbers > n){
                h = m-1;
            }else if(magic_numbers < n){
                l = m+1;
            }else{
                if(m%a == 0 || m%b == 0)
                    return m%1000000007;
                else
                    return (m-min(m%a,m%b))%1000000007;
            }
        }
        return -1;
    }
};
