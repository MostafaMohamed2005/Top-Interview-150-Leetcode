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
    
    TreeNode* solve(int l, int r,vector<int>& nums){
        if(l > r)
        return nullptr;

        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        TreeNode* a = solve(l,mid-1,nums);
        TreeNode* b = solve(mid+1,r,nums);

        node -> left = a;
        node -> right = b;

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};