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
    int answer = 0;
    pair<int, int> solve (TreeNode* node){
        if (node == NULL){
            return {0, 0};
        }
        pair<int, int> left = solve(node -> left);
        pair<int, int> right = solve (node -> right);

        int sum = node -> val + left.first + right.first;
        int count = 1 + left.second + right.second;

        int average = sum/count;
        
        if (average == node -> val){
            answer++;
        }
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        solve (root);
        return answer;
    }
};