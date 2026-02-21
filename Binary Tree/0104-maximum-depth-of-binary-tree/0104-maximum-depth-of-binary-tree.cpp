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
    int ans = 0;
    void solve(TreeNode * node, int le){
        if(node == nullptr)
        return;
        ans = max(ans,le);
        solve(node -> left, le + 1);
        solve(node -> right, le + 1);
    }
    int maxDepth(TreeNode* root) {
        solve(root,1);
        return ans;
    }
};