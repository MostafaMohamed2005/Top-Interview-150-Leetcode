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
    int level[105]={};
    void solve(TreeNode* node, int cur_level){
        if(node == nullptr)
        return;
        level[cur_level] = node->val;
        solve(node->left,cur_level+1);
        solve(node->right,cur_level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        for(int i=0 ; i < 105 ; i++)
        level[i] = 1e9;

        solve(root,1);
        vector<int>ans;
        for(int i=1 ; i < 105 ; i++)
        {
            if(level[i] == 1e9)
            break;
            ans.push_back(level[i]);
        }

        return ans;
    }
};