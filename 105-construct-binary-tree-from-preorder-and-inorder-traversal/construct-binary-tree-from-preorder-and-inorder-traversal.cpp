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
    TreeNode *build(int &idx, vector<int>& preorder, vector<int>& inorder, int s, int e){
        if(s > e)return NULL;
            TreeNode *temp = new TreeNode(preorder[idx]);
        
        int iidx = find(inorder.begin(),inorder.end(),preorder[idx])-inorder.begin();
        idx++;
        temp -> left = build(idx, preorder, inorder,s,iidx-1);
        temp->right = build(idx, preorder, inorder , iidx+1,e);

        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        return build(idx, preorder, inorder, 0, n-1 ); 
    }
};