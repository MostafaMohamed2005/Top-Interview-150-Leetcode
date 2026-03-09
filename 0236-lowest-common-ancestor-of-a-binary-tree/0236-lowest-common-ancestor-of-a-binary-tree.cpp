/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
class Solution {
public:
    const int LOG = 20, N = 1e5 + 7;

    unordered_map<int,vector<int>>adj;
    map<pair<int,int>,int>up;
    unordered_map<int,int>depth;

    void dfs(int node, int parent) {
        for (int ch:adj[node]) {
            if (ch != parent) {
                depth[ch] = depth[node] + 1;
                up[{ch,0}] = node;
                for (int j=1 ; j < LOG ; j++ ) {
                    up[{ch,j}]  = up[{up[{ch,j-1}],j-1}];
                }

                dfs(ch,node);
            }
        }
    }

    int get_lca(int a, int b) {
        if (depth[a] < depth[b]) {
            swap(a,b);
        }

        int depth_diff = depth[a] - depth[b];
        for (int i=LOG-1 ; i >= 0 ; i--) {
            if ((depth_diff>>i)&1) {
                a = up[{a,i}];
            }
        }

        if (a == b)
        return a;

        for (int i=LOG-1 ; i >= 0 ; i--) {
            if (up[{a,i}]  != up[{b,i}] ) {
                a = up[{a,i}]; 
                b = up[{b,i}]; 
            }
        }

        return up[{a,0}];
    }

    void solve(TreeNode* node){
        if(node == nullptr)
        return;

        if(node->left != nullptr){
            adj[node->val].push_back(node->left->val);
            solve(node->left);
        }

        if(node -> right != nullptr){
            adj[node->val].push_back(node->right->val);
            solve(node->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int root_val = root -> val;
        solve(root);
        dfs(root_val,root_val);
        TreeNode* ans = new TreeNode(get_lca(p->val,q->val));
        return ans;
    }
};