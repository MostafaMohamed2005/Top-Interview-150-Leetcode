class Solution {
public:
    int dp[10004];
    int solve(long long sum,vector<int>& coins, int amount){
        if(sum > amount)
        return 1e9;
        if(sum == amount)
        return 0;

        int &ret = dp[sum];
        if(~ret) return ret;
        ret = 1e9;
        for(int i=0 ; i < coins.size() ; i++)
        ret = min(ret,solve(sum+coins[i],coins,amount)+1);

        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,coins,amount);
        return(ans == 1e9 ? -1 : ans);
    }
};