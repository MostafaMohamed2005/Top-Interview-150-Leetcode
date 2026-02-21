class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[305][305]={};
    int n,m;
    void solve(int x, int y,vector<vector<char>>& grid){
        if(x >= n || y >= m|| x < 0 || y < 0 || grid[x][y] == '0'||vis[x][y])
        return;
        vis[x][y] = true;
        for(int i=0 ; i < 4 ; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            solve(xx,yy,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(),m = grid[0].size();
        int ans=0;
        for(int i=0 ; i < n ; i++){
            for(int j=0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    solve(i,j,grid);
                }
            }
        }

        return ans;
    }
};