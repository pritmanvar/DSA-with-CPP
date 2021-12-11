// problem Link : https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = NULL;
        ListNode* ans_head = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum;
            if(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 == NULL && l2 != NULL){
                sum = l2->val + carry;
                l2 = l2->next;
            }else if(l1 != NULL && l2 == NULL){
                sum = l1->val + carry;
                l1 = l1->next;
            }else{
                sum = carry;
            }
            
            
            if(ans == NULL){
                ans = new ListNode(sum%10);
                ans_head = ans;
            }else{
                ans->next = new ListNode(sum%10);
                ans = ans->next;
            }
            carry = sum/10;
        }
        return ans_head;
    }
};
