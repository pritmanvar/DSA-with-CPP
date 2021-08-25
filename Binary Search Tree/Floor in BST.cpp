// Problem Link : https://practice.geeksforgeeks.org/problems/implementing-floor-in-bst/1/?track=P100-Binary%20Search%20Tree&batchId=197#

// there are 2 major cases and after that there are some subcases
// 1. data of current node is less than key
//      a. right of current root is NULL
//          in this case there is not any possibility that i can get larger value which is smaller than key so answer will be data of current node
//      b. right is not NULL
//          in this case i will call floor function for right child and see that can i get larger floor than current one
//          if there is larger floor then i will return that else i will return data of current node
// 2. Data of current node is greater or equal to key
//      a. data of current node is equal to key 
//          in this case i will return current node because i can't get any node whose data is smaller than key and larger than current node since my current node is equal to key
//      b. Left child of my current node is NULL
//          here data of current node is larger than key and there isn't any smaller data than current one so i will return -1
//      c. Left child is not NULL
//          here data of current node is larger than key so i will call floor function for the left subtree to get it's floor value since left subtree contains smaller data then current one
int floor(Node* root, int key) 
{
    if(root->data < key){               // case 1.
        if(root->right == NULL){        // case 1(a)
            return root->data;
        }else{                          // case 1(b)
            int pos = floor(root->right,key);
            if(pos != -1)
                return pos;
            else
                return root->data;
        }
    }else{                              // cae 2.
        if(root->data == key)           // case 2(a)
            return key;
        else if(root->left == NULL)     // case 2(b)
            return -1;
        else                            // case 2(c)
            return floor(root->left,key);
    }
}
