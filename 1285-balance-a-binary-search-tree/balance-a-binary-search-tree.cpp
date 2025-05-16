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
    void inorder(TreeNode* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}

TreeNode* balanced(vector<int> &arr,int start ,int end){
    if(start > end){
        return NULL;
    }
    if(start == end){
        return new TreeNode(arr[start]);
    }
    int mid = start + (end-start)/2;

    TreeNode *root = new TreeNode(arr[mid]);
    root ->left = balanced(arr,start,mid-1);
    root->right = balanced(arr,mid+1,end);

    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
    inorder(root,arr);

    int size = arr.size();

    TreeNode *result = balanced(arr, 0 ,size-1);
    return result;
    }
};