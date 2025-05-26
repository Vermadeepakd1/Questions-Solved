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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        int rotate = k % size;
        int pass = size - rotate - 1;
        temp = head;

        while (pass--) {
            temp = temp->next;
        }
        ListNode* head2 = temp->next;

        temp->next = NULL;

        temp = head2;
        if (head2 == NULL) {
            return head;
        }
        cout << head2->val << endl;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        return head2;
    }
};