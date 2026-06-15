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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head,*prev=NULL;
        while(fast->next != NULL){
            prev=slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL)fast = fast->next;
        }
        if(prev == NULL)return NULL;

        prev->next = slow->next;
        slow->next = NULL;
        return head;
    }
};