// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int a,b,c,d,e,f,g,h;
        cin >> a >> b >> c;
        cin >> d >> e;
        cin >> f >> g >> h;

        int ans = 0;
        if((a+c)%2 == 0 && (a+c)/2 == b)
            ans++;
        if((a+f)%2 == 0 && (a+f)/2 == d)
            ans++;
        if((f+h)%2 == 0 && (f+h)/2 == g)
            ans++;
        if((c+h)%2 == 0 && (c+h)/2 == e)
            ans++;
        
        int pre = ans;
        int n = (a+h)/2;
        int tp = 1;
        if((a+h)%2 == 0){
            if((b+g)%2 == 0 && (b+g)/2 == n)
                tp++;
            if((c+f)%2 == 0 && (c+f)/2 == n)
                tp++;
            if((d+e)%2 == 0 && (d+e)/2 == n)
                tp++;
            ans = max(ans,pre+tp);
        }
      
        n = (b+g)/2;
        tp = 1;
        if((b+g)%2 == 0){
            if((a+h)%2 == 0 && (a+h)/2 == n)
                tp++;
            if((c+f)%2 == 0 && (c+f)/2 == n)
                tp++;
            if((d+e)%2 == 0 && (d+e)/2 == n)
                tp++;
            ans = max(ans,pre+tp);
        }
      
        n = (c+f)/2;
        tp = 1;
        if((c+f)%2 == 0){
            if((a+h)%2 == 0 && (a+h)/2 == n)
                tp++;
            if((b+g)%2 == 0 && (b+g)/2 == n)
                tp++;
            if((d+e)%2 == 0 && (d+e)/2 == n)
                tp++;
            ans = max(ans,pre+tp);
        }
      
        n = (d+e)/2;
        tp = 1;
        if((d+e)%2 == 0){
            if((a+h)%2 == 0 && (a+h)/2 == n)
                tp++;
            if((b+g)%2 == 0 && (b+g)/2 == n)
                tp++;
            if((c+f)%2 == 0 && (c+f)/2 == n)
                tp++;
            ans = max(ans,pre+tp);
        }
      
        cout << "Case #" << z << ": " << ans << endl;
    }
    return 0;
}
