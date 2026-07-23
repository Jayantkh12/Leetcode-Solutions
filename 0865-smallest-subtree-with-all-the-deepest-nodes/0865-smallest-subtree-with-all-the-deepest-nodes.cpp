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
        int maxDepth = 0;
    unordered_map<TreeNode*, int> mp;

    TreeNode* lca(TreeNode* root) {
        if (root == NULL)
            return NULL;

        if (mp[root] == maxDepth)
            return root;

        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if (l != NULL && r != NULL)
            return root;

        return (l == NULL) ? r : l;
    }

    void depth(TreeNode* root, int d) {
        if (root == NULL)
            return;

        maxDepth = max(maxDepth, d);
        mp[root] = d;

        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);
        return lca(root);
    }
};