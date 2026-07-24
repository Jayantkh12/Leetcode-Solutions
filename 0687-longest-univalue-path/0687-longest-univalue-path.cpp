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
    int solve(TreeNode* root,int& cnt){
        if(root == NULL) return 0;
        int left = solve(root->left,cnt);
        int right = solve(root->right,cnt);
        int leftpath=0;
        int rightpath=0;
        if(root->left && root->left->val==root->val){
            leftpath = left+1;
        }
        if(root->right && root->right->val==root->val){
            rightpath = right+1;
        }
        cnt = max(cnt,leftpath+rightpath); 
        return max(leftpath,rightpath);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int cnt = 0;
        solve(root,cnt);
        return cnt;
    }
};