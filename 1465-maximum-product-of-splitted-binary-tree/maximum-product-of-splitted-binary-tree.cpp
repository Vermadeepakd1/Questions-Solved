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
    long long totalsum = 0, maxi = 0;
    void dfs(TreeNode* root, long long &totalsum){
        totalsum += root->val;
        if(root->left)dfs(root->left,totalsum);
        if(root->right)dfs(root->right,totalsum);
    }

    int subtreeSum(TreeNode* root){
        if(!root)return 0;
        int leftsum = subtreeSum(root->left);
        int rightsum = subtreeSum(root->right);

        int currsum = leftsum + rightsum + root->val;
        int rem = totalsum - currsum;

        maxi = max(maxi,1ll*currsum*rem);
        return currsum;
    }
public:
    int maxProduct(TreeNode* root) {
        dfs(root,totalsum);

        maxi = 0;
        subtreeSum(root);
        return maxi%1000000007;
    }
};