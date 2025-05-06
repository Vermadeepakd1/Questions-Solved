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
        
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0, sum = 0;
        while (temp1 || temp2 || carry) {
            int first = temp1 ? temp1->val : 0;
            int second = temp2 ? temp2->val : 0;

            sum = first + second + carry;
            int newdata = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(newdata);
            temp = temp -> next;
            if (temp1) {
                temp1 = temp1->next;
            }
            if (temp2) {
                temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
};