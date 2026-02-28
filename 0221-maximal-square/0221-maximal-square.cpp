class Solution {
public:
    int dp[302][302];
    int solve(int i, int j,vector<vector<char>>& v){
        int n = v.size(),m = v[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m)
        return 0;
        

        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = 0;
        
        if(v[i][j] == '1')
        ret = 1 + min(solve(i+1,j+1,v),min(solve(i+1,j,v),solve(i,j+1,v)));

        return ret;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size(),ans = 0;
        memset(dp,-1,sizeof dp);
        for(int i=0; i < n ; i++){
            for(int j=0 ; j < m ; j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }

        return ans*ans;
    }
};