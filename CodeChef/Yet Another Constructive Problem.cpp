// Problem Link : https://www.codechef.com/START24B/problems/ORANDCON
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int x;
        cin >> x;

        if(x == 1){ // special case
            cout << 1 << " " << 3 << " " << 5 << endl;
            continue;
        }
        int a = 0,b,c = 0;
        b = x; // b will be x and i will create a and c respectively.

        int count = 0;
        while(x > 0){
            if(x%2 == 1){
                if(a == 0){ // a will contain only 1 set bit and it's position will be position of right most set bit in x
                    a = a | (a << count);
                }else{ // every other set bit in x will be set in c
                    c = c | (1 << count);
                }
            }else{
                c = c << 1;
            }
            x /= 2;
            count++;
        }
        if(a == b){ // if number contains only 1 set bit then i will make last unset bit set in a to make a and b different numbers
            a = a&(a-1);
        }
        if(c == 0){
            c = b;
            c = c | (1 << count); // if c is zero then i will make c = x and then will set first bit set to make a and b different numbers.
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
