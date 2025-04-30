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
    ListNode* reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr  = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        ListNode *temp = head;
        while(temp != NULL){
            int sum = carry + (temp ->val)*2;
            int num  = sum %10;
            carry = sum / 10;

            curr -> next = new ListNode(num);
            curr = curr ->next;
            temp = temp -> next;
        }
        while(carry){
            curr -> next = new ListNode(carry %10);
            carry /= 10;
        }
        dummy -> next = reverse(dummy->next);
        return dummy->next;
    }
};