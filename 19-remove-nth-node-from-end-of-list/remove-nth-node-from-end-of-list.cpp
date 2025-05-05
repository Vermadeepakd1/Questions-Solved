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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr){
            temp = temp -> next;
            len++;
        }
        int idx = len - n;
        if(idx == 0){
            temp = head -> next;
            head -> next = nullptr;
            delete head;
            head = temp;
            return head;
        }
        temp = head;
        int cnt = 0;
        while(cnt < idx-1){
            temp = temp -> next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
};