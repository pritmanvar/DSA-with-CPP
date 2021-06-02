//Problem Link : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
    
    // This question can be solved by the technic of multiplication which we had followed in our school days
    vector<int> factorial(int N){
        vector<int> vec;
        vec.push_back(1);
        
        //This loop is for find factorial.
        for(int i = N; i > 1; i--){
            int ans = 1;
            int rem = 0;
            //This loop is for find answer of multiphication. 
            for(int j = 0; j < vec.size(); j++){
                ans = i*vec[j];
                ans = ans + rem;
                vec[j] = ans%10;
                rem = ans/10;
            }
            while(rem != 0){
                int temp = rem%10;
                vec.push_back(temp);
                rem/=10;
            }
        }
        //we will reverse the answer because we had stored it in reverse order to do multiphication easily.
        reverse(vec.begin(),vec.end());
        return vec;
    }
