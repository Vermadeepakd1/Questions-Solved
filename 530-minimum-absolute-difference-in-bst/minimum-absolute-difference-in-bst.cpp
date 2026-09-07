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
public:
    int mini = INT_MAX;
    void findmin(TreeNode* root, int &prev) {
        if (root->left) {
            findmin(root->left, prev);
        }
        if (prev != -1) {
            mini = min(mini, abs(prev - root->val));
        }
        prev = root->val;
        if (root->right)
            findmin(root->right, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        findmin(root, prev);
        return mini;
    }
};