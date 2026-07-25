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
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool even = true;

        while (!q.empty()) {
            int n = q.size();

            int prev = even ? INT_MIN : INT_MAX;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (even) {
                    if (node->val % 2 == 0) return false;
                    if (node->val <= prev) return false;
                } else {
                    if (node->val % 2 != 0) return false;
                    if (node->val >= prev) return false;
                }

                prev = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            even = !even;
        }
        return true;
    }
};