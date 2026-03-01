class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&v, int k, int x, int n){
        if(!k){
            ans.push_back(v);
            return;
        }

        if(x > n)
        return;
        //cout << k << " " << x << endl;
        

        v.push_back(x);
        solve(v,k-1,x+1,n);
        v.pop_back();
        solve(v,k,x+1,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        solve(v,k,1,n);
        return ans;
    }
};