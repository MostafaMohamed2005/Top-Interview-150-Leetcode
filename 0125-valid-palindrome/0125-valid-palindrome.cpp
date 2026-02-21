class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0 ; i< s.size() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
            t.push_back('a' + (s[i] - 'A'));
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            t.push_back(s[i]);
        }

        for(int i=0 ; i < t.size()/2 ; i++){
            if(t[i] != t[t.size()-i-1]){
                return false;
            }
        }

        return true;
    }
};