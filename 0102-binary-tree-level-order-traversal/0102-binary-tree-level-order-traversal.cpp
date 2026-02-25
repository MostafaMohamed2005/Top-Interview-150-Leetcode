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
    vector<vector<int>>level_nodes;

    void solve(TreeNode* node, int level){
        if(node == nullptr)
        return;

        if(level == level_nodes.size()){
            vector<int>v = {node->val};
            level_nodes.push_back(v);
        }
        else
        level_nodes[level].push_back(node->val);

        solve(node->left,level+1);
        solve(node->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root,0);
        return level_nodes;
    }
};