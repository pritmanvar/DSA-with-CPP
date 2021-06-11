// Problem Link : https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> count;
        int max1 = 0;
        int max2 = 0;
        string ans1 = "";
        string ans2 = "";
        for(int i = 0; i < n; i++){
            count[arr[i]]++;
            // Thia if-else construct is used to find 2nd max
            if(count[arr[i]] > max1){
                if(arr[i]!=ans1){
                    max2 = max1;
                    ans2 = ans1;
                }
                max1 = count[arr[i]];
                ans1 = arr[i];
            }else if(count[arr[i]] <= max1 && count[arr[i]] > max2 && arr[i]!=ans1){
                ans2 = arr[i];
                max2 = count[arr[i]];
            }
        }
        return ans2;
    }
