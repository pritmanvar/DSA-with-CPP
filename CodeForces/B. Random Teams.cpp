// Problem Link : https://codeforces.com/problemset/problem/478/B

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ll n,m;
    cin >> n >> m;

    ll min,max;

    // to get maximum number of pairs i will try to maximize the number of participants in any one team
    // for that i will devide participants in such way that exactly m-1 team will contain only 1 participant
    // and 1 team will contain rest of participants that will be n-m+1.
    // now possible number of pair will be (n-m+1)C2.
    max = (n-m+1)*(n-m)/2;

    // to get minimum number of pairs i will try to minimize the number of participants in every team
    // for that i will try to divide participants amoung all team equaly.
    // but there will be n%m teams who will get one extra participant.
    // now possible number of pair will be (number of teams having n/m participants)*(n/m)C2 + (number of teams having n/m+1 participants)*(n/m+1)C2.
    min = (m-n%m)*(n/m)*(n/m-1)/2 + (n%m)*(n/m+1)*(n/m)/2;

    cout << min << " " << max << endl;
    return 0;
}
