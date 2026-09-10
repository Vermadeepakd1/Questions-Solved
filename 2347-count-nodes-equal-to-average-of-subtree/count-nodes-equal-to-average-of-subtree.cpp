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
    // no. of nodes, sum
    int cnt = 0;
    pair<int,int> solve(TreeNode * root){
        if(root == NULL){
            return {0,0};
        }
        
        auto leftsol = solve(root->left);
        auto rightsol = solve(root->right);

        int numnodes = leftsol.first + rightsol.first +1;
        int sum = root->val + leftsol.second + rightsol.second;

        if(sum/numnodes == root->val)cnt++;

        return {numnodes, sum};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return cnt;
    }
};