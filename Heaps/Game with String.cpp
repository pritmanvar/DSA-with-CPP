// Problem Link : https://practice.geeksforgeeks.org/problems/game-with-string4100/1#
    int minValue(string s, int k){
        int arr[26] = {0}; // to store frequency of every char
        // updating frequency array
        for(int i = 0; i < s.length(); i++){
            arr[s[i]-'a']++;
        }
        priority_queue<int> pq; // declaring max priority queue
        int value = 0; // our answer
        // adding frequency of every char into priority queue and updating value
        for(int i = 0; i < 26; i++){
            if(arr[i] > 0){
                pq.push(arr[i]);
                value += arr[i]*arr[i];
            }
        }
        for(int i = 0; i < k && pq.size() > 0; i++){
            // getting most frequent char
            int temp = pq.top();
            pq.pop();
            // reducing its frequency by 1 and updating value and adding new frequency into priority queue
            value += (temp-1)*(temp-1)-temp*temp;
            if(temp-1 > 0)
                pq.push(temp-1);
        }
        return value; // return answer
    }
