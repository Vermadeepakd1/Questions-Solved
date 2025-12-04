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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto it : lists) {
            if (it != NULL)
                pq.push(it);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            temp->next = it;
            temp = temp->next;
            it = it->next;
            if (it != NULL) {
                pq.push(it);
            }
        }
        return dummy->next;
    }
};