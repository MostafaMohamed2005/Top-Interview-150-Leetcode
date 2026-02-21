class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int row_up = 0,row_down = n-1,col_right = m-1,col_left = 0;
        vector<int>ans;
        while(ans.size() < n*m){
            for(int i=col_left ; i <= col_right ; i++)
            ans.push_back(matrix[row_up][i]);
            row_up++;

            for(int i=row_up ; i <= row_down ; i++)
            ans.push_back(matrix[i][col_right]);
            col_right--;

            for(int i=col_right ; i >= col_left ; i--)
            ans.push_back(matrix[row_down][i]);
            row_down--;

            for(int i=row_down ; i >= row_up ;i--)
            ans.push_back(matrix[i][col_left]);
            col_left++;
        }

        while(ans.size() > n*m)
        ans.pop_back();
        return ans;
    }
};