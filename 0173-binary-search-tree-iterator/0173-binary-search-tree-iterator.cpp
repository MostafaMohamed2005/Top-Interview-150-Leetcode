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
    stack<TreeNode*>tree;

    void solve(TreeNode* node){
        if(node == nullptr)
        return;

        tree.push(node);
        solve(node -> left);
    }   

    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        TreeNode* node = tree.top();
        int ans = tree.top() -> val;
        tree.pop();
        solve(node -> right);
        return ans;
    }
    
    bool hasNext() {
        return !tree.empty();
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