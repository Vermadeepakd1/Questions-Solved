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
    void getinorder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        getinorder(root->left, inorder);
        inorder.push_back(root->val);
        getinorder(root->right, inorder);
    }

    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        vector<int> newarr(m + n);
        int first = 0, second = 0, index = 0;
        while (first < m && second < n) {
            if (arr1[first] <= arr2[second]) {
                newarr[index] = arr1[first];
                index++;
                first++;
            } else {
                newarr[index] = arr2[second];
                index++;
                second++;
            }
        }
        while (first < m) {
            newarr[index] = arr1[first];
            first++;
            index++;
        }
        while (second < n) {
            newarr[index] = arr2[second];
            index++;
            second++;
        }
        return newarr;
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1, inorder2;
        getinorder(root1, inorder1);
        getinorder(root2, inorder2);
        vector<int> merged = merge(inorder1, inorder2);
        return merged;
    }
};