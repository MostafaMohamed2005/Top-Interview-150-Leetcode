class Solution {
public:
    int lengthOfLastWord(string s) {
        int le = 0,ans = 0;
        for(int i=0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                if(le)
                ans = le;
                le = 0;
            }
            else
            le++;
        }   

        if(le)
        ans = le;

        return ans;
    }
};