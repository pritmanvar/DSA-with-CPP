// Problem Link : https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#
int countRev(string s)
{
    deque<char> dq;
    int ans = 0;
    
    // if there are odd number of brackets then we can't convert it into balanced expression by reversing
    if (s.length() % 2 == 1)
        return -1;
        
    // i will use deque as stack and remove brackets which are valid
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '{'){ // if it is opening then push it into stack
            dq.push_back(s[i]);
        }else{
            // if closing and last one is opening then this set is valid so i will pop it
            // else push it
            if (dq.size() == 0 || dq.back() == '}'){
                dq.push_back(s[i]);
            }else{
                dq.pop_back();
            }
        }
    }

    int n = dq.size();
    float open = 0; // to count the number of opening brackets

    while(dq.empty() == false && dq.front() == '}'){
        open++;
        dq.pop_front();
    }
    float close = n-open; // to count the number of closing brackets
    
    // if there is even number of opening brackets then we have to do n/2 reversal
    // and if odd then n/2+1 means ceil(n/2)
    // same with closing brackets
    return (int)(ceil(open/2)+ceil(close/2));
}
