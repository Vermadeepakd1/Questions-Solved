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
    void solve(TreeNode* root, vector<string> &result,string temp){
        if((root->left == NULL && root ->right == NULL) ){
            temp += to_string(root->val);
            result.push_back(temp);
            return;
        }
        
        temp += to_string(root -> val) + "->";
        if(root -> left)
        solve(root->left,result,temp);
        if(root ->right)
        solve(root->right,result,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp = "";
        solve(root,result,temp);
        return result;
    }
};