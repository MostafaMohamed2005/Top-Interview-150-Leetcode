class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    int x;
    void solve(int i, vector<int>cur, int total){
        if(total == x){
            ans.push_back(cur);
            return;
        }
        if(i == v.size())
        return;

        solve(i+1,cur,total);
        int new_total = total;
        while(new_total <= x){
            new_total += v[i];
            cur.push_back(v[i]);
            solve(i+1,cur,new_total);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        v = candidates;
        x = target;
        vector<int>a;
        solve(0,a,0);
        return ans;
    }
};