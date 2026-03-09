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
    int index = 0;
    unordered_map<int,int>pos;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l > r)
        return nullptr;
        
        int value = pos[preorder[index]];
        TreeNode *node = new TreeNode(preorder[index++]);

        node -> left = solve(preorder,inorder,l,value-1);
        node -> right = solve(preorder,inorder,value+1,r);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0 ; i < inorder.size() ; i++)
        pos[inorder[i]] = i;

        return solve(preorder,inorder,0,inorder.size()-1);
    }
};

/*
    inorder: node -> left -> right
    preorder: left -> node -> right
*/