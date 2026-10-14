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
    void inorder(TreeNode* root, vector<int>& ls) {
        if (root->left)
            inorder(root->left, ls);
        if (root->left == NULL && root->right == NULL)
            ls.push_back(root->val);
        if (root->right)
            inorder(root->right, ls);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ls1;
        inorder(root1, ls1);
        vector<int> ls2;
        inorder(root2, ls2);
        return ls1 == ls2;
    }
};