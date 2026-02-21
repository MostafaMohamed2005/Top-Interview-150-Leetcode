class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int mi = 1000;
        for(int i=0 ; i < strs.size() ; i++)
        mi = min(mi,(int)strs[i].size());

        for(int i=0 ; i < mi ; i++){
            for(int j=1 ; j < strs.size() ; j++){
                if(strs[j][i] != strs[j-1][i]){
                    return s;
                }
            }

            s += strs[0][i];
        }

        return s;
    }
};