class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),sum=0,ans=-1e9;
        for(int i=0 ;  i < n ; i++){
            sum += nums[i];
            ans = max(ans,sum);
            if(sum < 0)
            sum = 0;
        }

        return ans;
    }
};