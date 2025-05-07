/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev = NULL, *curr = node,*next = NULL;
        while(curr -> next != NULL){
            next = curr ->next;
            curr ->val = next->val;
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
    }
};