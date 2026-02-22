class Solution {
public:
    unordered_map<string,bool>word;
    int dp[302];

    int solve(int i, string s){
        if(i == s.size())
        return 1;

        int &ret = dp[i];
        if(~ret) return ret;
        ret = 0;
        string x = "";
        for(int j=i ; j < s.size() ; j++){
            x += s[j];
            //cout << x << endl;
            if(word[x]){
                ret |= solve(j+1,s);
            }
        }

        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0 ; i< wordDict.size() ; i++)
        word[wordDict[i]]=true;
        memset(dp,-1,sizeof dp);
        return solve(0,s);
    }
};