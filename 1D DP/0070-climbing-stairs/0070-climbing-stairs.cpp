class Solution {
public:
    int dp[46][2];
    int solve(int steps, int climb){
        if(!steps)
        return 1;
        if(steps < 0)
        return 0;

        int &ret = dp[steps][climb];
        if(~ret) return ret;

        ret = solve(steps-1,0) + solve(steps-2,1);
        return ret;
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        int ans = solve(n,0);
        return ans;
    }
};