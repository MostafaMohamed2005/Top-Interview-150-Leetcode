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
class BSTIterator {
public:
    vector<int>tree;
    int index = 0;
    void solve(TreeNode* node){
        if(node == nullptr)
        return;

        solve(node -> left);
        tree.push_back(node->val);
        solve(node -> right);
    }   

    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        return tree[index++];
    }
    
    bool hasNext() {
        return (index < tree.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 /*

 */