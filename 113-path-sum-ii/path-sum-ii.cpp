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
    vector<int> path;
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;

        //leaf node encounter
        if (root->left == NULL && root->right == NULL){
            if (targetSum == 0){
                ans.push_back(path);
                
            }
            path.pop_back();
            return;
        }

        solve(root->left, targetSum);
        solve(root->right, targetSum);

        path.pop_back(); //backtrack
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};