class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "",zero = "";
        int n = a.size(),m = b.size();
        for(int i=0 ; i < max(n,m)-min(n,m) ; i++)
        zero += '0';

        if(b.size() > a.size())
        a = zero + a;
        else if(a.size() > b.size())
        b = zero + b;

        int rest = 0;
        for(int i=a.size()-1 ; i >= 0 ; i--){
            int total = (a[i]-'0') + (b[i]-'0') + rest;
            //cout << total << endl;
            if(total == 1 || total == 3)
            ans.push_back('1');
            else
            ans.push_back('0');
            //cout << ans << endl;

            if(total >= 2)
            rest = 1;
            else
            rest = 0;
        }

        if(rest)
        ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};