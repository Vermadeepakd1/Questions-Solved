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
    void findlength(TreeNode* root,int curr, int &length){
        if(root == NULL){
            length = max(length,curr);
            return;
        }
        findlength(root->left,curr+1,length);
        findlength(root->right,curr+1,length);

    }
public:
    int maxDepth(TreeNode* root) {
        int length = 0;
        if(root == NULL) return length;
        findlength(root,0,length);
        return length;
    }
};