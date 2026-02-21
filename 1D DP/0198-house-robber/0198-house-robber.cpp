class Solution {
public:
    int dp[102];
    int n;
    int solve(int house,vector<int>& nums){
        if(house >= n)
        return 0;

        int &ret = dp[house];
        if(~ret) return ret;

        ret = max(solve(house+1,nums),solve(house+2,nums)+nums[house]);

        return ret;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof dp);
        int ans = solve(0,nums);
        return ans;
    }
};

