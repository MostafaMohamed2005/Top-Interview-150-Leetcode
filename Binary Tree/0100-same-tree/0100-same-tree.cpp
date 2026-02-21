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
    void solve(TreeNode *node, vector<int>&v){
        if(node == nullptr){
            v.push_back(1e9);
            return;
        }

        v.push_back(node -> val);
        solve(node -> left, v);
        solve(node -> right, v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>a,b;
        solve(p,a);
        solve(q,b);

        if(a.size() != b.size())
        return false;

        for(int i=0 ; i < a.size() ; i++){
            if(a[i] != b[i])
            return false;
        }

        return true;
    }
};