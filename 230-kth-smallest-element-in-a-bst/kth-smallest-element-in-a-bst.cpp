/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int ans = -1;
    void findk(TreeNode* root, int k, int& curr) {
        if (root == NULL)
            return;
        findk(root->left, k, curr);
        if (ans != -1)
            return;
        if (curr == k) {
            ans = root->val;
            cout << root->val << endl;
            return;
        }
        curr++;
        findk(root->right, k, curr);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int curr = 1;
        findk(root, k, curr);
        return ans;
    }
};