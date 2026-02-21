class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>e1,e2;
        for(int i=0 ; i < s.size() ; i++){
            if(!e1.contains(s[i]) && !e2.contains(t[i]))
            e1[s[i]] = t[i], e2[t[i]] = s[i];
            else if(e1[s[i]] != t[i] || e2[t[i]] != s[i])
            return false;
        }

        return true;
    }
};