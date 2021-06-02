    // Problem Link : https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays1618/1/?track=P100-Searching&batchId=197#4
    
    //I had used merge function of merge function but insted of use an array i had made 2 variable because i need only 2 elements to find median
    int findMedian(int arr1[], int n, int arr2[], int m)
    {
        int ind = (n+m)/2;
        int ans1 = 0;
        int ans2 = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                ans1 = ans2;
                ans2 = arr1[i];
                i++;
                k++;
            }else{
                ans1 = ans2;
                ans2 = arr2[j];
                j++;
                k++;
            }
            if(k == ind+1){
                if((n+m)%2 == 0)
                    return (ans1+ans2)/2;
                else
                    return ans2;
            }
        }
        while(i < n){
            ans1 = ans2;
            ans2 = arr1[i];
            i++;
            k++;
            if(k == ind+1){
                if((n+m)%2 == 0)
                    return (ans1+ans2)/2;
                else
                    return ans2;
            }
        }
        while(j < m){
            ans1 = ans2;
            ans2 = arr2[j];
            j++;
            k++;
            if(k == ind+1){
                if((n+m)%2 == 0)
                    return (ans1+ans2)/2;
                else
                    return ans2;
            }
        }
        return 0;
    }