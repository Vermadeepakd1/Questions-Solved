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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = new ListNode(-1);
        ListNode *b = new ListNode(-1);

        ListNode *less = a, *more=b;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> val < x){
                less -> next = temp;
                less = less->next;
            }else {
                more->next = temp;
                more=more->next;
            }

            temp = temp->next;
        }
        less->next = b->next;
        more->next = NULL;
        return a->next;
    }
};