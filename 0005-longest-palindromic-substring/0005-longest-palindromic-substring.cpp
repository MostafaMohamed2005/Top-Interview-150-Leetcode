class Solution {
public:
    int ans = 1,start=0;
    int dp[1002][1002];
    
    bool solve(int l, int r, string&s){
        if(l == r)
        return dp[l][r] = 1;
        if(l > r)
        return dp[l][r] = 0;

        int &ret = dp[l][r];
        if(~ret) return ret;
        ret = 0;

        if(r-l+1 >= 3 && s[l] == s[r] && solve(l+1,r-1,s) == 1)
        ret = 1;

        if(r-l+1 == 2 && s[l] == s[l+1])
        ret = 1;
        
        //cout << l << " " << r << " " << ret << endl;

        solve(l+1,r,s);
        solve(l,r-1,s);

        
        if(ret == 1){
            if(r-l+1 >= ans)
            ans = r-l+1,start = l;
        }

        return ret;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        solve(0,s.size()-1,s);
        string x = s.substr(start,ans);
        return x; 
    }
};