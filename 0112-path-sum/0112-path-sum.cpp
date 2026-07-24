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
    bool ans = false;
    void solve(TreeNode* root,int targetSum) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            if(targetSum == root->val) ans=true;
            return;
        }
        solve(root->left,targetSum-(root->val));
        solve(root->right,targetSum-(root->val));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return ans;
    }
};