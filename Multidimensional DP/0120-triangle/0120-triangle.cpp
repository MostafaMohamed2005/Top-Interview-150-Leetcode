class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(),ans = 1e9;
        int dp[2][205]={};
        dp[0][0] = triangle[0][0];
        if(n == 1)
        ans = dp[0][0];
        for(int i=1 ; i < n;  i++){
            for(int j=0 ; j <= i ; j++){
                dp[i&1][j] = 1e9;
                if(j != i)
                dp[i&1][j] = dp[!(i&1)][j];
                if(j-1 >= 0)
                dp[i&1][j] = min(dp[i&1][j],dp[!(i&1)][j-1]);
                dp[i&1][j] += triangle[i][j];
                if(i == n-1)
                ans = min(ans,dp[i&1][j]);
            }
        }

        return ans;
    }
};