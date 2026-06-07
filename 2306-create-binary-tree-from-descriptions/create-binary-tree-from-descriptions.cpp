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

    TreeNode* buildtree(int root, unordered_map<int,int>&left, unordered_map<int,int>&right){
        TreeNode *temp = new TreeNode(root);
        if(left[root]){
            temp->left = buildtree(left[root],left,right);
        }
        if(right[root]) temp->right = buildtree(right[root],left,right);

        return temp;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> left,right;
        set<int>st;

        for(auto &v : descriptions){
            int p = v[0],c = v[1], l = v[2];
            if(l){
                left[p] = c;
            }else right[p]= c;
            st.insert(c);
        }
        int root = -1;
        for(auto &v : descriptions){
            if(!st.count(v[0])){root = v[0];
            break;}
        }
        TreeNode *result = buildtree(root, left,right);
        return result;
    }
};