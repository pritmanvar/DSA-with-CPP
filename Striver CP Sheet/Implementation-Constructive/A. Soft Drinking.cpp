#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,l,c,d,p,nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totalLiter = k*l, limes = c*d;
    cout << min(totalLiter/nl,min(limes,p/np))/n << endl;
    return 0;
}
 
