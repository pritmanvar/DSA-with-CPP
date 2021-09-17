// Problem Link : https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1#
    
    unordered_map<Node*,pair<int,char>> mp; // map to store ancestors of target in formate of<root,<distance,subtree>>
    vector<int> ans; // to store answer
    
    // This function will find ancestors of the target and store that in the map 
    void fillancestors(Node* root, int target, int* dist){
        if(root == NULL) // base case
            return;
        
        // if current node is equal to target then i will add that into map with distance 0 and subtree where targer found none
        if(root->data == target){
            mp[root] = {0,'n'};
            *dist = 0;
            return;
        }
        
        int ldist = -1,rdist = -1; // to store distance from current node to target in left and right subtree.
        // call function for left subtree
        fillancestors(root->left,target,&ldist);
        
        // if target is founded in the left subtree
        // then i will add current node as ancestor of target with distance ldist+1 and subtree where target is found left
        if(ldist != -1){
            mp[root] = {ldist+1,'l'};
            *dist = ldist+1;
            return;
        }
        // call function for right subtree
        fillancestors(root->right,target,&rdist);
        
        // if target is founded in the right subtree
        // then i will add current node as ancestor of target with distance rdist+1 and subtree where target is found right
        if(rdist != -1){
            mp[root] = {rdist+1,'r'};
            *dist = rdist+1;
            return;
        }
    }
    // This function will find node at distance dist in its descendants and store that into ans vector.
    void getNodeatDist(Node* root, int dist){
        if(root == NULL) // base case
            return;
        
        // if required distance is 0 then i will add current node into ans
        if(dist == 0){ 
            ans.push_back(root->data);
            return;
        }
        // call for left and right subtree with distance = dist-1
        getNodeatDist(root->left,dist-1);
        getNodeatDist(root->right,dist-1);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // reset global variables
        mp.clear();
        ans.clear();
        
        // initilize distance form target as -1
        int dist = -1;
        
        // find ancestors of target
        fillancestors(root,target,&dist);
        
        // traverse though all ancestors
        for(auto i : mp){
            // if current node is at distance k then add that into ans
            if(i.second.first == k){
                ans.push_back(i.first->data);
                continue;
            }
            // if current node is target then call for getNodeatDist from current node with distance k
            if(i.second.second == 'n'){
                getNodeatDist(i.first,k);
            }else if(i.second.second == 'l'){ // if target founded in left subtree then call for getNodeatDist for the right subtree and distance = k-distance of current node - 1
                getNodeatDist(i.first->right,k-i.second.first-1);
            }else{ // if target founded in right subtree then call for getNodeatDist for the left subtree and distance = k-distance of current node - 1
                getNodeatDist(i.first->left,k-i.second.first-1);
            }
        }
        sort(ans.begin(),ans.end()); // sort ans vector
        return ans; // return answer
    }
