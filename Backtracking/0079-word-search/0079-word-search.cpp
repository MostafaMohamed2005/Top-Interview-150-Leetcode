class Solution {
public:
    bool vis[10][10];
    bool e = false;
    int size,n,m;
    string s;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void solve(int i, int j, int word_i, vector<vector<bool>>&v,vector<vector<char>>& board){
        if(e)
        return;
        if(word_i == size){
            e = true;
            return;
        }

        

        for(int z=0; z < 4 ; z++){
            int a = i + dx[z];
            int b = j + dy[z];
            if(valid(a,b) && !v[a][b] && s[word_i] == board[a][b]){
                v[i][j] = 1;
                solve(a,b,word_i+1,v,board);
                v[i][j] = 0;
                if(e)
                return;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        size = word.size();
        n = board.size(),m = board[0].size();
        for(int i=0 ; i < n; i++){
            for(int j=0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>v(n,vector<bool>(m));
                    solve(i,j,1,v,board);
                    if(e)
                    return true;
                }
            }
        }

        return false;

    }
};