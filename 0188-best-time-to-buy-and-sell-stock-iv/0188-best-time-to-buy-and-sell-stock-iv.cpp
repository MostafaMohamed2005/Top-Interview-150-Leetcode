class Solution {
public:
    int dp[1002][204];
    int solve(int index,int cur_k,int k, vector<int>& prices){
        if(index == prices.size() || cur_k == k)
        return 0;

        int &ret = dp[index][cur_k];
        if(~ret) return ret;
        ret = 0;

        if(cur_k%2 == 0){
            //take
            ret = max(ret,-prices[index] + solve(index+1,cur_k+1,k,prices));
            //leave
            ret = max(ret,solve(index+1,cur_k,k,prices));
        }else{
            //take
            ret = max(ret,prices[index] + solve(index+1,cur_k+1,k,prices));
            //leave
            ret = max(ret,solve(index+1,cur_k,k,prices));
        }

        return ret;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,2*k,prices);
        return ans;
    }
};