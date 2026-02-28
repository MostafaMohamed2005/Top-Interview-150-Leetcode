class Solution {
public:
    int dp[102][102][2];
    int solve(int i, int j,int si,string s1, string s2, string s3){

        //cout << i << " " << j << " " << z << endl;
        if(i == s1.size() && j == s2.size() && i+j == s3.size())
        return 1; 

        if((!si && s1.size() == i) || (si && s2.size() == j) || i+j == s3.size())
        return 0;


        int &ret = dp[i][j][si];
        if(~ret) return ret;

        ret = 0;

        if(!si && s1[i] == s3[i+j]){
            //take 
            ret |= solve(i+1,j,1,s1,s2,s3);
            //leave
            ret |= solve(i+1,j,0,s1,s2,s3);
        }else if(si && s2[j] == s3[i+j]){
            //take 
            ret |= solve(i,j+1,0,s1,s2,s3);
            //leave
            ret |= solve(i,j+1,1,s1,s2,s3);
        }

        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        bool ans = solve(0,0,0,s1,s2,s3) | solve(0,0,1,s1,s2,s3);
        return ans;
    }
};

/*
    status:
    dp[s1_index][s2_index][s3_index][2]
    transitions:
    if(s1[i] == s3[i]){
        //take 

        //leave
    }
*/