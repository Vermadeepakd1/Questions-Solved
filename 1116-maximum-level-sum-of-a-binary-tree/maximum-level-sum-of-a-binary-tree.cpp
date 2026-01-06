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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int maxi = root->val, maxlvl = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int x = q.size();
            int lvlsum = 0;
            level++;
            for(int i = 0; i<x; i++){
                auto top = q.front();
                q.pop();
                lvlsum += top->val;
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }

            if(lvlsum > maxi){
                maxlvl = level;
                maxi = lvlsum;
            }
        }

        return maxlvl;
    }
};