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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        map<int, int> mp;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        mp[0] = root->val;

        while (!q.empty()) {

            pair<TreeNode*, int> front = q.front();
            q.pop();
            int level = front.second;
            TreeNode* frontnode = front.first;

            mp[level] = frontnode->val;

            if (frontnode->left) {
                q.push({frontnode->left, level + 1});
            }

            if (frontnode->right) {
                q.push({frontnode->right, level + 1});
            }
        }
        for (auto it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};