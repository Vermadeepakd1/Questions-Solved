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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL)return {};
        vector<vector<int>> result;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;

            for(int i = 0; i<n; i++){
                TreeNode *t = q.front();
                temp.push_back(t->val);

                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                q.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
};