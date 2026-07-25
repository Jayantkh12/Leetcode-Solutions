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
    void pathFromNode(TreeNode* root, long long curr, int targetSum, int &ans) {
        if (!root) return;

        curr += root->val;
        
        if (curr == targetSum) ans++;

        pathFromNode(root->left, curr, targetSum, ans);
        pathFromNode(root->right, curr, targetSum, ans);
    }

    void solve(TreeNode* root, int targetSum, int &ans) {
        if (!root) return;

        pathFromNode(root, 0, targetSum, ans);

        solve(root->left, targetSum, ans);
        solve(root->right, targetSum, ans);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        solve(root, targetSum, ans);
        return ans;
    }
};