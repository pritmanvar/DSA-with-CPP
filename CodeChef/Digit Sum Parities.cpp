// Problem Link : https://www.codechef.com/COOK140B/problems/DIGSMPAR

#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int gtsum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        int sumn = gtsum(n);
        n++;
        int sumt = gtsum(n);

        while(sumn%2 == sumt%2){
            n++;
            sumt = gtsum(n);
        }
        cout << n << endl;
    }
    return 0;
}
