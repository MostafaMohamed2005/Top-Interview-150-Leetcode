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

    void solve(string&s, int n,int cnt){
        //cout << s << endl;
    
        if(s.size() == n){
            if(check(s))
            ans.push_back(s);
            return;
        }

        if(cnt < 0)
        return;

        s.push_back('(');
        solve(s,n,cnt+1);
        s.pop_back();
        s.push_back(')');
        solve(s,n,cnt-1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s,2*n,0);
        return ans;            
    }
};