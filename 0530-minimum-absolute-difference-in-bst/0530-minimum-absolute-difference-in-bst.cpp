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
    void solve(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left , ans);
        solve(root->right , ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        int count = INT_MAX;
        solve(root,ans);
        sort(ans.begin(), ans.end());
        for(int i=1;i<ans.size();i++){
            count = min(count,abs(ans[i]-ans[i-1]));
        }
        return count;
    }
};