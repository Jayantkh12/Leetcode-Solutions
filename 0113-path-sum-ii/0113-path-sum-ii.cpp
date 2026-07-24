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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int targetSum, vector<int>curr , vector<vector<int>>&ans) {
        if (root == NULL) return;
        curr.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if(targetSum == root->val) ans.push_back(curr);
            return;
        }
        solve(root->left,targetSum-(root->val), curr, ans);
        solve(root->right,targetSum-(root->val), curr, ans);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum,{},ans);
        return ans;
    }
};