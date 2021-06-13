// GCD of three or more numbers equals the product of the prime factors common to all the numbers
// it can also be calculated by repeatedly taking the GCDs of pairs of numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
 // for more info: https://www.geeksforgeeks.org/gcd-two-array-numbers/
