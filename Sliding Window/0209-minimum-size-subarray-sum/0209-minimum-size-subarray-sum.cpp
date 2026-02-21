class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
        int n = nums.size(),ans = 1e9;
        vector<int>pre;
        pre.push_back(nums[0]);
        for(int i=1 ; i < n ; i++)
        pre.push_back(pre.back()+nums[i]);
        
        for(int i=0 ; i < n ; i++){
            int value = (i == 0 ? 0 : pre[i-1]) + target;
            auto it = lower_bound(pre.begin(),pre.end(),value);
            if(it == pre.end())
            break;
            int size = (it - pre.begin()) - i + 1;
            ans = min(ans,size);
        }

        return (ans == 1e9 ? 0 : ans);
    }
};