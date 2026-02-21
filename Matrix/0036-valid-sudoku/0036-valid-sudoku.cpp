class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        //cout << 1 << endl;
        for(int i=0 ; i < n ; i++){
            unordered_map<int,bool>m;
            for(int j=0 ; j < n ; j++){
                if(board[i][j] == '.')
                continue;
                if(m[board[i][j]])
                return false;
                m[board[i][j]] = true;
            }
        }

        //cout << 2 << endl;
        for(int i=0 ; i < n ; i++){
            unordered_map<int,bool>m;
            for(int j=0 ; j < n ; j++){
                if(board[j][i] == '.')
                continue;
                if(m[board[j][i]])
                return false;
                m[board[j][i]] = true;
            }
        }

        //cout << 3 << endl;
        for(int i=0 ; i < n ; i += 3){
            for(int j=0 ; j < n ; j += 3){
                unordered_map<int,bool>m;
                for(int a = i ; a < i+3  ; a++){
                    for(int b = j ; b < j+3 ; b++){
                        if(board[a][b] == '.')
                         continue;
                        if(m[board[a][b]])
                        return false;
                        m[board[a][b]] = true;
                    }
                }
            }
        }

        return true;
    }
};