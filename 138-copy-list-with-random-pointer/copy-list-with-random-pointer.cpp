/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        if(head == NULL) return NULL;
        Node *head2 = new Node(head->val);
        mp[head] = head2;
        Node *temp  = head;
        Node *temp2 = head2;
        while(temp -> next != nullptr){
            temp = temp ->next;
            Node *newnode = new Node(temp->val);
            temp2 ->next = newnode;
            temp2= temp2 ->next;
            mp[temp] = temp2;
        }
        temp = head;
        temp2 = head2;
        while(temp != NULL){
            temp2 -> random = mp[temp->random];
            temp = temp ->next;
            temp2 = temp2 ->next;
        }
        return head2;
    }
};