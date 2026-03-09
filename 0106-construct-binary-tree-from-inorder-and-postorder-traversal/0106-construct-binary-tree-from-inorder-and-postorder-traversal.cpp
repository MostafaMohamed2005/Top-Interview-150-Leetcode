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
    int index;
    unordered_map<int,int>pos;

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int l, int r){
        if(l > r)
        return nullptr;
        
        int value = pos[postorder[index]];
        TreeNode *node = new TreeNode(postorder[index--]);

        node -> right = solve(postorder,inorder,value+1,r);
        node -> left = solve(postorder,inorder,l,value-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0 ; i < inorder.size() ; i++)
        pos[inorder[i]] = i;
        index = inorder.size()-1;
        return solve(postorder,inorder,0,inorder.size()-1);
    }
};