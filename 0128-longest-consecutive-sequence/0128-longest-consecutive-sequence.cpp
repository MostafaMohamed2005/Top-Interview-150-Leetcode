class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>m;
        int n = nums.size();
        for(int i=0 ; i < n ; i++)
        {
            if(!m.count(nums[i]))
            m[nums[i]]=true;
        }

        int last = -(1e9+7),cnt = 0,ans = 0;
        for(auto [key,value]:m)
        {
            if(last+1 == key)
            cnt++;
            else
            cnt = 1;

            cout << key << " ";
            ans = max(ans,cnt);
            last = key;
        }

        return ans;
    }
};