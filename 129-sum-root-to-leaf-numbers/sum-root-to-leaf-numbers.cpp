/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode * root, int curr){
        if(root== NULL)ans += curr;
        curr = curr*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ans += curr;
        }
        if(root->left)solve(root->left,curr);
        if(root->right)solve(root->right,curr);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};