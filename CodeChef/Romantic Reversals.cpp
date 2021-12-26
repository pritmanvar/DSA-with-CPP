// Problem Link : https://www.codechef.com/LTIME103B/problems/RMNTREV

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

string getOriginal(string str, int k){
    int i = 0,j = k-1;
    string original;
    int counter = 0;
    while(i <= j){
        if(counter%2 == 0){
            original += str[i];
            i++;
        }else{
            original += str[j];
            j--;
        }
        counter++;
    }
    reverse(original.begin(),original.end());

    return original;
}
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;

        string str;
        cin >> str;

        string str1 = str.substr(0,k);
        string str2 = str.substr(k,str.length()-k);

        string original = getOriginal(str1,k);
        string ans = original + str2;

        cout << ans << endl;
    }
    return 0;
}
