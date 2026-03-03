class Solution {
public:
    bool vis[203][203],exist = false;
    int n,m;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    vector<pair<int,int>>v;

    bool valid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void solve(int i, int j, vector<vector<char>>& board){
        v.push_back({i,j});
        vis[i][j]=1;
        if(!i || i == n-1 || !j || j == m-1) 
        exist = true;

        for(int a = 0 ; a < 4 ; a++){
            int x = i + dx[a];
            int y = j + dy[a];

            if(valid(x,y) && !vis[x][y] && board[x][y] == 'O'){
                solve(x,y,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size(),m = board[0].size();

        for(int i=0 ; i < n ; i++){
            for(int j=0 ; j < m ; j++){
                v.clear();
                exist = false;
                if(!vis[i][j] && board[i][j] == 'O'){
                    solve(i,j,board);
                    if(!exist){
                        for(int z =0 ; z < v.size() ; z++){
                            int x = v[z].first,y = v[z].second;
                            board[x][y] = 'X';
                        }
                    }
                }
            }
        }
    }
};