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
int find(int n, vector<int> &in, int size){
        for(int i = 0; i<size; i++){
            if(in[i] == n){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int> &in, vector<int> &pre, int &index, int start, int end , int n, map<int,int> &mp){
        
        if(index >= n || start > end){
            return NULL;
        }
        
        int element = pre[index++];
        int p = mp[element];
        
        TreeNode *root = new TreeNode(element);
        root->left = solve(in,pre,index,start,p-1,n,mp);
        root->right = solve(in,pre,index,p+1,end,n,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preorderindex = 0;
        int n = inorder.size();
        TreeNode * result = solve(inorder,preorder,preorderindex,0,n-1,n,mp);
        return result;
    }
};