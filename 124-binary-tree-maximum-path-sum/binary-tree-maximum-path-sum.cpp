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
    int solve(TreeNode* root,int &maxsum) {
        if (!root) return 0;
        
        int left = solve(root->left,maxsum);
        int right = solve(root->right,maxsum);

        int sum = left + right + root ->val;
        maxsum = max(max(sum,root->val),max(maxsum,max(root->val +left, root->val +right)));
        return max(max(left,right) + root->val , max(root->val,max(root->val + left, root->val + right)));
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right ){
            return root->val;
        }
        int maxsum = INT_MIN;
        solve(root,maxsum);
        return maxsum;
    }
};