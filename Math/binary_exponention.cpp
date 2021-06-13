// for detailed info: https://cp-algorithms.com/algebra/binary-exp.html
// many a times in the contests, it is asked to find modulo along with exponention
// for eg.: to compute (x^y) % p
// this needs modulo after every iteration since not doing so can cause overflow of large numbers
// checkout above mentioned link to understand exactly what binary exponention algo is
long long power(long long a, long long b, long long m) 
{
    a%=m;
    long long res=1;
    while(b > 0) 
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
