class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        map<char,int>m;
        while(s.size() > r){
            if(r-1 > 0 && m[s[r-1]] == 2)
            m[s[l]]--,l++;
            else{
                m[s[r]]++;
                if(m[s[r]] == 1)
                ans = max(ans,r-l+1);
                r++;
            }
        }

        return ans;
    }
};