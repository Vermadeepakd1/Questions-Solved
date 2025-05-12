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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        vector<int> result;
        while(curr != NULL){
            if(curr -> left == NULL){
                result.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                TreeNode *prev = curr -> left;
                while(prev -> right != NULL && prev -> right != curr){
                    prev = prev -> right;
                }

                if(prev -> right == curr){
                    result.push_back(curr->val);
                    prev -> right = NULL;
                    curr = curr -> right;
                }
                else{
                    prev -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        return result;
    }
};