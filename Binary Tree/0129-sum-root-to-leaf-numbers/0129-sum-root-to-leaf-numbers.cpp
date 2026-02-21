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
    void solve(TreeNode* node, string sum){
        char x = '0' + (node -> val);
        sum.push_back(x);
        if(node->left == nullptr && node -> right == nullptr){
            ans += stoi(sum);
            return;
        }
        if(node -> left != nullptr)
        solve(node->left,sum);
        if(node -> right != nullptr)
        solve(node->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};