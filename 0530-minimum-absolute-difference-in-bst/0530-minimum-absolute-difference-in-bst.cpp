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
    multiset<int>s;
    void solve(TreeNode* node){
        if(node == nullptr)
        return;


        auto it = s.lower_bound(node->val);
        if(it != s.end())
        ans = min(ans,*it - node->val);
        if(it != s.begin())
        it--,ans=min(ans,node->val-*it);
        s.insert(node->val);

        solve(node->left);
        solve(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};