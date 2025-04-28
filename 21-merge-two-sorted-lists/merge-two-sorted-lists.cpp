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
    void solve(ListNode* list1, ListNode* list2){
        ListNode *prev = list1;
        ListNode *curr = list1->next;
        while(curr!= NULL && list2 != NULL){
            int preVal = prev->val;
            int currVal = curr->val;
            int check = list2->val;
            if(check >= preVal && check <= currVal){
                ListNode *temp = list2->next;
                prev->next = list2;
                list2->next = curr;
                prev = list2;
                list2 = temp;
            }else{
                prev = curr;
                curr = curr -> next;
            }
        }
        if(curr == NULL){
            prev->next = list2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        if(list1->val < list2 -> val){
            solve(list1,list2);
            return list1;
        }
        else{
            solve(list2,list1);
            return list2;
        }
    }
};