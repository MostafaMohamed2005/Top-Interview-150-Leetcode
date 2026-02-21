class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string w = "",ans = "";
        vector<string>v;
        for(int i=0 ; i < n ; i++)
        {
            if(s[i] == ' ')
            {
                if(w != "")
                v.push_back(w),w = "";
                continue;
            }

            w.push_back(s[i]);
        }

        if(w != "")
        v.push_back(w);

        for(int i=v.size()-1 ; i >= 0 ; i--)
        ans += (v[i]) + (i != 0 ? " " : "");
        return ans;
    }
};