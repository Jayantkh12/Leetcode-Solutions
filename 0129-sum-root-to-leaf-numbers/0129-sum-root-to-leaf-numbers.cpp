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
    void solve(TreeNode* root, string curr , int &ans) {
        if (root == NULL) return;
        curr.push_back(root->val+'0');

        if (root->left == NULL && root->right == NULL) {
            ans+= stoi(curr);
            return;
        }
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,"",ans);
        return ans;
    }
};