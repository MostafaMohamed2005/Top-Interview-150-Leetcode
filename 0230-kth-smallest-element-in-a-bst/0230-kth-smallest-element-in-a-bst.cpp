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
    vector<int>v;
    void solve(TreeNode* node){
        if(node == nullptr){
            return;
        }

        solve(node->left);
        v.push_back(node->val);
        solve(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        return v[k-1];
    }
};