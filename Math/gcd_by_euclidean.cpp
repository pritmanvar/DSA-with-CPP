#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
// this is based on euclidean algorithm which says:
// 1.If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
// 2.Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.
// for more info : https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
