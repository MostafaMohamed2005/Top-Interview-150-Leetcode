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

    void show(TreeNode *node){
        if(node == nullptr){
            cout << -1 << " ";
            return;
        }

        cout << node -> val << " ";
        show(node -> left);
        show(node -> right);
    }
    void solve(TreeNode *node, vector<int>&v){
        if(node == nullptr){
            v.push_back(1e9);
            return;
        }

        v.push_back(node -> val);
        get(node -> left, v);
    
        get(node -> right, v);
    }

    void get(TreeNode *node, vector<int>&v){
        if(node == nullptr){
            v.push_back(1e9);
            return;
        }

        v.push_back(node -> val);
        solve(node -> right, v);
        solve(node -> left, v);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>a,b;
        TreeNode* x = root;
        show(x);
        solve(root->left,a);
        get(root->right,b);
    
        if(a.size() != b.size())
        return false;

        for(int i=0 ; i < a.size() ; i++){
            if(a[i] != b[i])
            return false;
        }

        return true;
    }
};