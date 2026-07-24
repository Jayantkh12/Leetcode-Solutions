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

    void solve(TreeNode* root, int cnt ,bool curr ){
        if(root == NULL) return ;
        ans = max(ans,cnt);
        
        if(curr){
            solve(root->left,cnt+1,false);
            solve(root->right,1,true);
        }
        else{
            solve(root->right,cnt+1,true);
            solve(root->left,1,false);
        }
    }
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        int cnt = 0;
        solve(root->left,1,false);
        solve(root->right,1,true);
        return ans;
    }
};