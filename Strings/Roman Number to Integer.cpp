// Problem Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
int romanToDecimal(string &str) {
    // code here
    int n = 0;
    int ind= 0;
    int ans = 0;
    for(int i = str.length()-1; i >= 0; i--){
        switch(str[i]){
            case 'I' :
                if(n > 1){
                    ans -= 1;
                }else{
                    ans+=1;
                }
                n = 1;
                break;
            case 'V' :
                if(n > 2){
                    ans -= 5;
                }else{
                    ans+=5;
                }
                n = 2;
                break;
            case 'X' :
                if(n > 3){
                    ans -= 10;
                }else{
                    ans += 10;
                }
                n = 3;
                break;
            case 'L' :
                if(n > 4){
                    ans -= 50;
                }else{
                    ans += 50;
                }
                n = 4;
                break;
            case 'C' :
                if(n > 5){
                    ans -= 100;
                }else{
                    ans += 100;
                }
                n = 5;
                break;
            case 'D' :
                if(n > 6){
                    ans -= 500;
                }else{
                    ans += 500;
                }
                n = 6;
                break;
            case 'M' :
                if(n > 7){
                    ans -= 1000;
                }else{
                    ans += 1000;
                }
                n = 7;
                break;
        }
    }
    return ans;
}
