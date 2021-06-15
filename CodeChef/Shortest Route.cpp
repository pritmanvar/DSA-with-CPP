// Problem Link : https://www.codechef.com/JUNE21C/problems/SHROUTE

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int trains[n];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        // int tra[m];
        for(int i = 0; i < n; i++){
            scanf("%d",&trains[i]);
            if(i != 0){
                if(trains[i] == 1){
                    dp1[i] = i;
                }else{
                    dp1[i] = dp1[i-1];
                }
            }else{
                if(trains[0] == 1){
                    dp1[0] = 0;
                }
            }
        }
        if(trains[n-1] == 2){
            dp2[n-1] = n-1;
        }
        for(int i = n-2; i >= 0; i--){
            if(trains[i] == 2){
                dp2[i] = i;
            }else{
                dp2[i] = dp2[i+1];
            }
        }
        for(int i = 0; i < m; i++){
            int manjil;
            scanf("%d",&manjil);
            manjil--;//3
            if(manjil == 0){
                printf("%d ",0);
                continue;
            }
            int ind1 = dp1[manjil];//0
            int ind2 = dp2[manjil];//4


            if(ind1 == -1 && ind2 == -1){
                printf("%d ",-1);
            }else if(ind1 == -1 && ind2 >= 0){
                printf("%d ",ind2-manjil);
            }else if(ind1 >= 0 && ind2 == -1){
                printf("%d ",manjil - ind1);
            }else{
                printf("%d ",min((ind2-manjil),(manjil-ind1)));
            }
        }
        printf("\n");
    }
    return 0;
}
