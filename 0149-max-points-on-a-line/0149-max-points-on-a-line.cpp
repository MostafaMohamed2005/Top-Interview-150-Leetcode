class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),ans = 1;
        for(int i=0 ; i < n ; i++){
            unordered_map<long double,int>slope_cnt;
            for(int j=i+1 ; j < n ; j++){
                long double slope = (long double)(points[i][1]-points[j][1]);

                if(!(points[i][0]-points[j][0]))
                slope = 1e9;
                else
                slope /= (points[i][0]-points[j][0]);

                slope_cnt[slope]++;
                ans = max(ans,slope_cnt[slope]+1);
            }
        }

        return ans;
    }
};
