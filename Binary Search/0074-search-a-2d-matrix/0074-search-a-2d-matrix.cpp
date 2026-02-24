class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();

        for(int i=0 ; i < m ; i++){
            if(target > matrix[i].back())
            continue;
            auto it = lower_bound(matrix[i].begin(),matrix[i].end(),target);
            if(*it == target){
                return true;
            }
        }

        return false;
    }
};