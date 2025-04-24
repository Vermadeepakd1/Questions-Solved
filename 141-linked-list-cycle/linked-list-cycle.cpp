/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *,bool> mp;
        ListNode *temp = head;
        while(temp != NULL && mp[temp] != true){
            mp[temp] = true;
            temp = temp -> next;
        }
        if(temp == NULL){
            return false;
        }
        return true;
    }
};