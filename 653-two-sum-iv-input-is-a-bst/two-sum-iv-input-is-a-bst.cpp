/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        int size = arr.size();

        int left = 0, right = size - 1;

        while (left < right) {
            if (arr[left] + arr[right] == k) {
                return true;
            } else if (arr[left] + arr[right] > k) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};