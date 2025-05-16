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
    TreeNode* create(vector<int>& preorder, int mini, int maxi, int& index,
                     int size) {
        if (index >= size || preorder[index] < mini || preorder[index] > maxi) {
            return NULL;
        }

        int val = preorder[index];
        TreeNode* root = new TreeNode(val);
        index++;

        root->left = create(preorder, mini, val, index, size);
        root->right = create(preorder, val, maxi, index, size);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return create(preorder, INT_MIN, INT_MAX, index, preorder.size());
    }
};