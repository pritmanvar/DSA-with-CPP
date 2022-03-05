// Problem Link : https://codeforces.com/contest/371/problem/C
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

// this function will check that is it possible to make 'number' hamburgers with available resources.
// it will return true if it is possible and false if it is not possible.
bool isPossible(ll number, int nb, int ns, int nc, int pb, int ps, int pc, ll r, int b, int s, int c){
    if(nb < number*b && r < (number*b - nb)*pb){
        return false;
    }else if(nb < number*b){
        r -= (number*b - nb)*pb;
    }
    if(ns < number*s && r < (number*s - ns)*ps){
        return false;
    }else if(ns < number*s){
        r -= (number*s - ns)*ps;
    }

    if(nc < number*c && r < (number*c - nc)*pc){
        return false;
    }else if(nc < number*c){
        r -= (number*c - nc)*pc;
    }

    return true;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // accept input.
    string str;
    cin >> str;
    int nb,ns,nc;
    cin >> nb >> ns >> nc;
    int pb,ps,pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;

    // count number of 'b', 's' and 'c' to create single hamburger
    int b = 0,s = 0,c = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'B')
            b++;
        else if(str[i] == 'S')
            s++;
        else
            c++;
    }

    ll ans = 0;
    ll lower_limit = 0, upper_limit; // lower limit and upper limit of binary search.

    // set upper limit
    if(b > 0)
        upper_limit = (nb + r/pb)/b;
    else if(s > 0)
        upper_limit = (ns + r/ps)/s;
    else
        upper_limit = (nc + r/pc)/c;

    // binary search.
    while(lower_limit <= upper_limit){
        ll mid = lower_limit + (upper_limit-lower_limit)/2;
        // if it is possible to create mid number of hamburgers then i will try to increase mid by ignoring left half 
        // if it is not possible then i will ignore right half.
        if(isPossible(mid,nb,ns,nc,pb,ps,pc,r,b,s,c)){ 
            ans = mid;
            lower_limit = mid+1;
        }else{
            upper_limit = mid-1;
        }
    }
    cout << ans << endl; // print Answer.
}
