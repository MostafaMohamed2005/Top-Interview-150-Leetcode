class Solution {
public:
    vector<string>ans;
    bool check(string &x){
        int cnt = 0;
        for(int i=0 ; i < x.size() ; i++){
            if(x[i] == '(')
            cnt++;
            else{
                if(!cnt)
                return false;
                else
                cnt--;
            }
        }

        return (cnt > 0 ? false : true);
    }

    void solve(string&s, int n){
        cout << s << endl;
        if(s.size() == n){
            if(check(s))
            ans.push_back(s);
            return;
        }


        s.push_back('(');
        solve(s,n);
        s.pop_back();
        s.push_back(')');
        solve(s,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s,2*n);
        return ans;            
    }
};