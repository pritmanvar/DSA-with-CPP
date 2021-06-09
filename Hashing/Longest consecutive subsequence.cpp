// Problem Link : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
    int findLongestConseqSubseq(int arr[], int N)
    {
        // I had used set insted of unordered_set 
        // because in unordered_set if lowest element in longest subsequance is comes in middle then it can give wrong answer
        set<int> st;
        // Adding every element in the set
        for(int i = 0; i < N; i++){
          st.insert(arr[i]);
        }
        int answer = 1;
        int temp = 1;
        for(auto i : st){
            // checking that previous element is present or not if present then we will increse the length of current subsequance
            if(st.count(i-1) == 1){
                temp++;
            }else{// if previous element is not present then we will set length as 1 and start new subsequance from that
                answer = max(temp,answer);
                temp = 1;
            }
        }
        answer = max(temp,answer);
        return answer;
    }
