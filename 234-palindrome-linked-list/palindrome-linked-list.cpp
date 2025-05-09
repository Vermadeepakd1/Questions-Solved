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
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* middle = findMid(head);
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        ListNode *head1 = head, *head2 = middle->next;
        while (head2 != NULL) {
            if (head1->val == head2->val) {
                head1 = head1->next;
                head2 = head2->next;
            } else {
                return false;
            }
        }
        // ListNode* temp = middle->next;
        // middle->next = reverse(temp);
        return true;
    }
};