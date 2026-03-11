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
    
    void solve(TreeNode* node){
        if(node == nullptr)
        return;

        if(node -> left != nullptr){
            solve(node -> left);
            TreeNode* left = node -> left;
            TreeNode* last_node_left = node -> left;
            while(last_node_left -> right != nullptr)
            last_node_left = last_node_left -> right;

            node -> left = nullptr;
            last_node_left -> right = node -> right;
            node->right = left;
        }

        if(node -> right != nullptr){
            solve(node -> right);
        }
    }

    void flatten(TreeNode* root) {
        if(root == nullptr)
        root = nullptr;
        else
        solve(root);
    }
};

/*
    link left to right by accessing the last 
    node in the left and make the right the right node
*/