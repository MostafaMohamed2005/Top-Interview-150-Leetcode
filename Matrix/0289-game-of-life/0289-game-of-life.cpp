class Solution {
public:
    bool valid(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n; 
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>>v = board;
        int dx[8]={0,0,1,1,1,-1,-1,-1}; 
        int dy[8]={-1,1,-1,0,1,-1,0,1}; 

        for(int i=0 ; i < m ;i++){
            for(int j=0 ; j < n ; j++){
                int cnt = 0;
                //cout << "/////////////////////\n";
                for(int z=0 ; z < 8 ; z++){
                    int x = i + dx[z];
                    int y = j + dy[z]; 
                    //cout << x << " " << y << endl;
                    if(valid(x,y,m,n) && v[x][y] == 1)
                    cnt++;
                }

                //cout << i << " " << j << " " << cnt << endl;
                if(v[i][j] == 1 && (cnt < 2 || cnt > 3))
                board[i][j] = 0;
                else if(v[i][j] == 0 && cnt == 3)
                board[i][j] = 1;
            }
        }
    }
};