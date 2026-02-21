class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(),cnt = 1;
        vector<vector<int>>v;
        for(int i=0 ; i < n ; i++){
            v.push_back({points[i][0],-points[i][1]});
        }
        sort(v.begin(),v.end());
        int l = v[0][0],r = -v[0][1];
        for(int i=1 ; i < n ; i++){
            l = max(l,v[i][0]);
            r = min(r,-v[i][1]);
            if(l > r)
            l = v[i][0],r = -v[i][1],cnt++;
        }

        return cnt;
    }
};