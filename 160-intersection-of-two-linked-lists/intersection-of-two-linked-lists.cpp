class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;

        while (headA) {
            st.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (st.find(headB) != st.end()) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};
