class Solution {
public:

    int dp[102][102];
    int solve(int i, int j, vector<vector<int>>& v){
        int n = v.size(),m = v[0].size();
        if(i >= n || i < 0 || j >= m || j < 0 || v[i][j] == 1)
        return 0;

        if(i == n-1 && j == m-1)
        return 1;

        int &ret = dp[i][j];
        if(~ret) return ret;

        ret = solve(i+1,j,v) + solve(i,j+1,v);
        
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,obstacleGrid);
        return ans;
    }
};