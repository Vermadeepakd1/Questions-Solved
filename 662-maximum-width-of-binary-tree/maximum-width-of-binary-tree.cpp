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
    int widthOfBinaryTree(TreeNode* root) {
        int maxlength = 0;
        if(root == NULL){
            return maxlength;
        }
        queue<pair<TreeNode* ,unsigned long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int n = q.size();
            unsigned long long mmin = q.front().second ;
            unsigned long long leftmost,rightmost;
            for(int i = 0; i<n; i++){
                auto front = q.front();
                q.pop();

                TreeNode* frontnode = front.first;
                unsigned long long idx = front.second - mmin;

                if(i==0){
                    leftmost = idx;
                }
                if(i == n-1){
                    rightmost = idx;
                }
                

                if(frontnode -> left){
                    q.push({frontnode->left, 2 * idx +1});
                }
                if(frontnode -> right){
                    q.push({frontnode->right, 2 * idx +2});
                }

            }
            maxlength = max( (int)(rightmost - leftmost + 1), maxlength  );
        }
        return maxlength;
    }
};