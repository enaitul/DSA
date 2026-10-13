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
public:
    int minDepth(TreeNode* root) {

        // An empty tree has depth 0.
        if (root == nullptr) {
            return 0;
        }

        // If the current node has no left child,
        // the minimum depth must come from the right subtree.
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // If the current node has no right child,
        // the minimum depth must come from the left subtree.
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // Both children exist.
        // Take the smaller subtree depth and include this node.
        return 1 + min(
            minDepth(root->left),
            minDepth(root->right)
        );
    }
};
