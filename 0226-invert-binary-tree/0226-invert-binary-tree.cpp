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
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        if(root != nullptr)
        q.push(root);

        while(q.size())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp -> left != nullptr || temp -> right != nullptr)
            {
                if(temp -> left != nullptr)
                q.push(temp -> left);
                if(temp -> right != nullptr)
                q.push(temp ->right);
                
                TreeNode* sw = temp-> left;
               
                temp->left = temp -> right;
                temp->right = sw;   
            }
        }

        return root;
    }
};