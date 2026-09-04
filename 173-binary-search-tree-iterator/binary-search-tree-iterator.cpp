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
class BSTIterator {
public:
    void inorder(TreeNode* root, vector<int> &values){
        if(root->left)inorder(root->left,values);
        values.push_back(root->val);
        if(root->right)inorder(root->right,values);
    }
    vector<int> values;
    int i = -1,n=0;
    BSTIterator(TreeNode* root) {
        inorder(root,values);
        n = values.size();
    }
    
    int next() {
        i++;
        if(i >n )return -1;
        return values[i];
    }
    
    bool hasNext() {
        return i<n-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */