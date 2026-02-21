class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(),index = 0;
        vector<vector<int>>ans;
        if(intervals.empty())
        return {newInterval};
        if(newInterval[1] < intervals[0][0]){
            ans.push_back(newInterval);
            for(int i=0 ; i < n ; i++)
            ans.push_back(intervals[i]);
            return ans;
        }

        while(index != n && intervals[index][1] < newInterval[0]){
            ans.push_back(intervals[index]);
            index++;
        }

        

        if(index == n){
            ans.push_back(newInterval);
            return ans;
        }

        if(newInterval[1] >= intervals[index][0]){
            int l = min(intervals[index][0],newInterval[0]);
            int r = max(intervals[index][1],newInterval[1]);
            
            while(index != n && r >= intervals[index][0])
            r = max(r,intervals[index][1]),index++;

            ans.push_back({l,r});
        }
        else
        ans.push_back(newInterval);

        for(int i=index ; i < n ; i++)
        ans.push_back(intervals[i]);

        return ans;
    }
};