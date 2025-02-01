/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int solve(TreeNode *root, int low, int high)
        {
            if (root == nullptr)
            {
                return 0;
            }
            int sum = 0;
            if (root->val >= low && root->val <= high)
            {
                sum += root->val;
            }
            sum += solve(root->left, low, high);
            sum += solve(root->right, low, high);
            return sum;
        }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return solve(root, low, high);
    }
};