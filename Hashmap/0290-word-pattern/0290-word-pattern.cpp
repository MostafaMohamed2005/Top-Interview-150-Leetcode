class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>e1;
        unordered_map<string,char>e2;
        vector<string>t;
        string st="";
        for(int i=0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                t.push_back(st);
                st = "";
                continue;
            }
            st.push_back(s[i]);
        }
        t.push_back(st);

        for(int i=0 ; i < min(pattern.size(),t.size()) ; i++){
            if(!e1.contains(pattern[i]) && !e2.contains(t[i]))
            e1[pattern[i]] = t[i], e2[t[i]] = pattern[i];
            else if(e1[pattern[i]] != t[i] || e2[t[i]] != pattern[i])
            return false;
        }

        // for(int i=0 ; i < t.size() ; i++){
        //     if(!e2.contains(t[i]))
        //     return false;
        //     else{
        //         char x = e2[t[i]];
        //         if(e1[x] != t[i])
        //         return false;
        //     }
        //}

        return (t.size() == pattern.size() ? true : false);
    }
};