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

    pair<int,int> diameterOpt(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterOpt(root->left);
        pair<int,int> right = diameterOpt(root->right);

        int d1 =left.first;
        int d2 = right.first;
        int d3 = left.second + right.second;

        pair<int,int> result;
        result.first = max(d1,max(d2,d3));
        result.second = 1 + max(left.second,right.second);

        return result;
    }

    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOpt(root).first;
    }
};