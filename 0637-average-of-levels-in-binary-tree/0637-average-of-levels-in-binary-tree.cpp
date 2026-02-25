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
    double level_cnt[10005],level_sum[10005];

    void solve(TreeNode* node, int level){
        if(node == nullptr)
        return;

        if(level_cnt[level] == -1)
        level_cnt[level] = 0;

        level_cnt[level]++;
        level_sum[level]+=node->val;

        solve(node -> left, level+1);
        solve(node -> right, level+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        for(int i=0 ; i <= 10000 ; i++)
        level_cnt[i] = -1;
        solve(root,0);

        vector<double>v;

        for(int i=0 ; i <= 10000 ; i++){
            //cout << level_cnt[i] << " ";
            if(level_cnt[i] == -1)
            break;
            v.push_back(level_sum[i]/level_cnt[i]);
        }

        return v;
    }
};