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
        if (head->next->next == NULL)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        int mini = INT_MAX;
        int firstp = -1, lastp = -1, prevp = -1, currp = -1;
        while (curr->next != NULL) {
            int cval = curr->val, pval = prev->val, nval = curr->next->val;

            if ((cval > pval && cval > nval) || (cval < pval && cval < nval)) {
                if (firstp == -1)
                    firstp = idx;
                prevp = currp;
                currp = idx;
                lastp = idx;

                if (prevp != currp && prevp !=-1) {
                    mini = min(mini, currp - prevp);
                }
            }

            idx++;
            prev = curr;
            curr = curr->next;
        }

        if (firstp == lastp)
            return {-1, -1};
        int maxi = lastp - firstp;

        return {mini, maxi};
    }
};