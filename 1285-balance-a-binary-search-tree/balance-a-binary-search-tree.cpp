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
    void inorder(TreeNode *root, vector<int>&arr){
        if(root == NULL)return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    TreeNode* createBalanced(vector<int> &arr, int s, int e){
        if(s>e){
            return NULL;
        }
        int mid = s+(e-s)/2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = createBalanced(arr,s,mid-1);
        root->right = createBalanced(arr,mid+1,e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int n = arr.size();
        TreeNode *result = createBalanced(arr,0,n-1);
        return result;
    }
};