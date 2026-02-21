class Solution {
public:
    vector<char>v[10];
    vector<string>ans;
    void solve(int i, string s, string digits){
        if(i == digits.size()){
            ans.push_back(s);
            return;
        }

        for(int j=0 ; j < v[digits[i]-'0'].size(); j++){
            solve(i+1,s+v[digits[i]-'0'][j],digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        v[2] = {'a','b','c'};
        v[3] = {'d','e','f'};
        v[4] = {'g','h','i'};
        v[5] = {'j','k','l'};
        v[6] = {'m','n','o'};
        v[7] = {'p','q','r','s'};
        v[8] = {'t','u','v'};
        v[9] = {'w','x','y','z'};
        solve(0,"",digits);
        return ans;
    }
};