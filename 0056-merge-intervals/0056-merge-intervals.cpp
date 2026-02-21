class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int l = intervals[0][0], r = intervals[0][1], n = intervals.size();
        vector<vector<int>>ans;

        for(int i=1 ; i < n ; i++){
            int curr_l = intervals[i][0],curr_r = intervals[i][1];
            if(curr_l <= r)
            r = max(r,curr_r);
            else{
                ans.push_back({l,r});
                l = curr_l,r = curr_r;
            }
        }


        ans.push_back({l,r});

        return ans;
    }
};