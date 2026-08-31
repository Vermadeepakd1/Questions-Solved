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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL)return {-1,-1};
        ListNode *prev = head;
        ListNode * curr = head->next;
        int idx = 1;

        vector<int> store;

        while(curr->next != NULL){
            int cval = curr->val, pval = prev->val, nval = curr->next->val;

            if(((cval > pval) == (cval > nval)) && cval != pval && cval != nval) store.push_back(idx);

            idx++;
            prev = curr;
            curr = curr->next;

        }

        for(int i : store)cout << i << " ";

        if(store.size() <=1 )return {-1,-1};
        int maxi = store[store.size()-1]-store[0];
        int mini = INT_MAX;
        for(int i = 0;i<store.size()-1; i++){
            mini = min(mini, store[i+1]-store[i]);
        }
        return {mini, maxi};
    }
};