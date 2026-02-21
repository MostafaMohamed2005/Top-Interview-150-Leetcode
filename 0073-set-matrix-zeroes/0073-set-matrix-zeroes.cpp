class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row = false,first_col = false;
        int m = matrix.size(),n = matrix[0].size();

        for(int i=0 ; i < n ; i++){
            if(matrix[0][i] == 0)
            first_row = true;
        }
        for(int i=0 ; i < m ; i++){
            if(matrix[i][0] == 0)
            first_col = true;
        }

        for(int i=1 ; i < m ; i++){
            for(int j=1 ; j < n ; j++){
                if(matrix[i][j] == 0)
                matrix[0][j] = matrix[i][0] = 0;
            }
        }

        for(int i=1 ; i < n ; i++){
            if(matrix[0][i] == 0){
                for(int j=0 ; j < m ; j++)
                matrix[j][i] = 0;
            }
        }

        for(int i=1 ; i < m ; i++){
            if(matrix[i][0] == 0){
                for(int j=0 ; j < n ; j++)
                matrix[i][j] = 0;
            }
        }

        //cout << first_row << " " << first_col << endl;
        if(first_row){
            for(int i=0 ; i < n ; i++){
            matrix[0][i] = 0;
          }
        }

        if(first_col){
            for(int i=0 ; i < m ; i++){
            matrix[i][0] = 0;
         }
        }
    }
};