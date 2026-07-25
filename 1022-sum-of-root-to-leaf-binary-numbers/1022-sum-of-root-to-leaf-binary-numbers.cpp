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
    void solve(TreeNode* root, string curr, int& ans) {
        if (root == NULL)
            return;
        curr.push_back(root->val + '0');
        if (root->left == NULL && root->right == NULL) {
            int num = 0;

            for (char c : curr) {
                num = num * 2 + (c - '0');
            }

            ans += num;
            return;
        }
        solve(root->left,curr, ans);
        solve(root->right,curr, ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root,"", ans);
        return ans;
    }
};