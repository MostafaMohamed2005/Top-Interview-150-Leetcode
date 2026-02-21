class Solution {
public:
    int dp[505][505];
    int solve(int i, int j,string s1,string s2)
    {
        if(i == s1.size())
        return s2.size() - j;

        if(j == s2.size())
        return s1.size() - i;

        int&ret = dp[i][j];
        if(~ret) return ret;
        ret = 1e9;

        if(s1[i] == s2[j])
        ret = solve(i+1,j+1,s1,s2);
        else
        {
            ret = min(solve(i+1,j+1,s1,s2)+1,
            min(solve(i,j+1,s1,s2)+1,solve(i+1,j,s1,s2)+1));
        }

        return ret;
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,word1,word2);
        return ans;
    }
};

