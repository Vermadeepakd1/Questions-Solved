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
    TreeNode* findlca(TreeNode* root, int n1, int n2){
        if(!root)return NULL;

        if(root->val == n1 || root->val == n2)return root;

        TreeNode* leftlca = findlca(root->left,n1,n2);
        TreeNode* rightlca = findlca(root->right,n1,n2);

        if(leftlca && rightlca)return root;

        return leftlca ? leftlca : rightlca;

    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)return root;

        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*> dpst;

        while(!q.empty()){
            int x = q.size();
            vector<TreeNode*>temp;

            while(x--){
                auto f = q.front();
                temp.push_back(f);
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            dpst = temp;
        }

        int x = dpst.size();

        return findlca(root,dpst[0]->val,dpst[x-1]->val);
    }
};