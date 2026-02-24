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
    void  findsum(TreeNode* root, int num, int &sum){
        if(root == NULL){
            return;
        }
        num = (num<<1)+root->val;
        if(root->left == NULL && root->right == NULL){
            sum += num;
        }
        findsum(root->left,num,sum);
        findsum(root->right,num,sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        findsum(root,0,sum);
        return sum;
    }
};