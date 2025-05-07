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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }

        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i<n; i++){
                TreeNode *frontnode = q.front();
                q.pop();
                int idx = leftToRight ? i : n-i-1;
                temp[idx] = frontnode -> val;
                if(frontnode -> left) q.push(frontnode->left);
                if(frontnode -> right) q.push(frontnode -> right);
            }

            result.push_back(temp);
            leftToRight = !leftToRight;
        }
        return result;
    }
};