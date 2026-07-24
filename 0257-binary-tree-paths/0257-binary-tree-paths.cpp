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
    void solve(TreeNode* root, string curr, vector<string>& ans) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (!curr.empty()) curr += "->";

            curr += to_string(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        if (!curr.empty()) curr += "->";
        curr += to_string(root->val);
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};