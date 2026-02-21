class Solution {
public:
    bool isAnagram(string s, string t) {
        int f1[30]={},f2[30]={};
        for(int i=0 ; i < s.size() ; i++)
        f1[s[i]-'a']++;

        for(int i=0 ; i < t.size() ; i++)
        f2[t[i]-'a']++;
        
        for(int i=0 ; i < 26 ; i++)
        if(f1[i] != f2[i])
        return false;
        return true;
    }
};