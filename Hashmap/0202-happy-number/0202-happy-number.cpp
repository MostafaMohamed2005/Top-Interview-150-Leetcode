class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>e;
        int l_n = n;
        e[n] = true;
        while(true){
            string s = to_string(l_n);
            n = 0;
            for(int i=0 ; i < s.size() ; i++)
            n += (s[i] - '0')*(s[i] - '0');

            if(n == 1)
            return true;
            if(e[n])
            return false;
            e[n] = true;
            l_n = n;
        }

        return false;
    }
};