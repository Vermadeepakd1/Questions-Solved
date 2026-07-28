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
    bool isvalid(TreeNode* root, long long l, long long r) {
        if (root == NULL)
            return true;

        bool curr = (l < root->val) && (r > root->val);
        if (!curr)
            return false;
        bool lr = isvalid(root->left, l, root->val);
        bool rr = isvalid(root->right, root->val, r);

        return (lr && rr);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root, LLONG_MIN, LLONG_MAX);
    }
};