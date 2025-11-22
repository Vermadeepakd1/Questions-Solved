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
    int max_d = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        max_d = max(max_d,leftH + rightH  );
        return max(leftH, rightH) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxDepth(root);
        return max_d;
    }
};