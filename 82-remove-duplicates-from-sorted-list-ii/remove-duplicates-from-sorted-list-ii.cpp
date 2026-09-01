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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL, *next = NULL;
        ListNode * dummy = new ListNode(-1);
        ListNode * a = dummy;

        while(temp != NULL){
            bool take = true;
            next = temp -> next;
            if(prev != NULL && prev->val == temp->val)take=false;
            if(next != NULL && next->val == temp->val)take = false;

            if(take){
                a->next = temp;
                a = a->next;
            }

            prev = temp;
            temp = next;

        }
        a->next = NULL;
        return dummy->next;
    }
};