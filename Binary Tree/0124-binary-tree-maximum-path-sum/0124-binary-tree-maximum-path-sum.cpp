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
    int ans = -1e9;
    int solve(TreeNode* node){
        if(node == nullptr)
        return 0;

        int left = solve(node -> left);
        int right = solve(node -> right);

        int value = left + right + (node -> val);
        ans = max(ans,value);

        return max(0,max(left,right)+(node->val));
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};