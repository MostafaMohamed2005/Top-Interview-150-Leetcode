class Solution {
public:
    int dp[205][205],n,m;
 
    int solve(int x,int y,vector<vector<int>>& grid)
    {
        if(x == n-1 && y == m-1)
        return 0;

        int &ret = dp[x][y];
        if(~ret) return ret;

        ret = 1e9;
        if(x+1 < n)
        ret = min(ret,solve(x+1,y,grid)+grid[x+1][y]);
        if(y+1 < m)
        ret = min(ret,solve(x,y+1,grid)+grid[x][y+1]);

        return ret;
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        n = grid.size(),m = grid[0].size();
        return solve(0,0,grid)+grid[0][0];
    }
};

/*
    statue
    dp[x][y][sum]
    transition
    ret = 1e18
    min(solve(x+1,y)+arr[x+1][y],solve(x,y+1)+arr[x][y+1])
*/