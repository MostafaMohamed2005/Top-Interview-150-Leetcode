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
    int ans = 1e9;
    vector<int>v;
    void solve(TreeNode* node){
        if(node == nullptr)
        return;   
        solve(node->left);
        v.push_back(node->val);
        solve(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        solve(root);
        for(int i=1 ; i < v.size() ; i++){
            ans = min(ans,v[i]-v[i-1]);
            if(i != v.size()-1)
            ans = min(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};