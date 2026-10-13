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
    TreeNode* build(vector<int>& nums, int left, int right) {

        // Base case: no elements remain in this range.
        if (left > right) {
            return nullptr;
        }

        // Find the middle index to keep the tree balanced.
        int mid = left + (right - left) / 2;

        // Create a tree node using the middle element.
        TreeNode* root = new TreeNode(nums[mid]);

        // Build the left subtree from the left half.
        root->left = build(nums, left, mid - 1);

        // Build the right subtree from the right half.
        root->right = build(nums, mid + 1, right);

        // Return the root of this subtree.
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        // Start with the entire array.
        return build(nums, 0, nums.size() - 1);
    }
};
