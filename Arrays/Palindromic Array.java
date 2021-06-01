// Problem Line : https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
	
    public static int palinArray(int[] a, int n){
        for(int i = 0; i < n; i++){ // Traverce through all array and check every element that it is palindrom or not
            if(!isPalindrom(a[i])){//if element is not a palindrom then we will return 0
                return 0;
            }
        }
        return 1;
    }
    // Functiion to check that number is palindrom or not
    public static boolean isPalindrom(int n){
        int temp = n;
        int count = 0;
        while(temp > 0){
            count++;
            temp/=10;
        }
        
        while(n > 9){
            int f = (int)(n/(Math.pow(10,count-1)));
            n -= f*Math.pow(10,count-1);
            int l = n%10;
            n/=10;
            count -= 2;
            if(l != f){
                return false;
            }
        }
        return true;
    }
