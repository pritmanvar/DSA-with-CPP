#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int s;
        cin >> s;
 
        int sum1 = 1;
        int bg1 = 1;
        int l1 = 1;
        int sum2 = 1;
        int bg2 = 1;
        int l2 = 1;
        bool first = true;
        while(s != sum1){
            if((s - sum1) < (bg1+2)){
                bg1 = s-sum1;
                sum1 = s;
                l1++;
            }else{
                l1++;
                bg1 = bg1+2;
                sum1 += bg1;
            }
 
            if((s-sum2) < (bg2+2)){
                bg2 = s-sum2;
                sum2 = s;
                l2++;
            }else{
                l2++;
                if(first){
                    bg2 += 1;
                }else{
                    bg2 += 2;
                }
                sum2 += bg2;
            }
        }
        cout << min(l1,l2) << endl;
    }
    return 0;
}
