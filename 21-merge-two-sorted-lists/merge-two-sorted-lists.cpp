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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* f = list1, *s = list2;

        while(f != NULL && s != NULL){
            if(f->val <= s->val){
                temp->next = f;
                f=f->next;
            }else{
                temp->next=s;
                s=s->next;
            }
            temp = temp->next;
        }
        if (f != NULL) {
            temp->next = f;
        } else {
            temp->next = s;
        }
        return dummy->next;
    }
};