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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        while (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            if (head == NULL) {
                return head;
            }
        }
        ListNode* temp = head;
        while (temp != NULL && temp -> next != NULL) {
            if (temp->next->val == val) {
                ListNode* temp2 = temp->next;
                temp->next = temp->next->next;
                temp2->next = NULL;
                delete temp2;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};