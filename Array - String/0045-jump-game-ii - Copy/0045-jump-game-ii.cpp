class Solution {
public:
    int jump(vector<int>& nums) {
        int max_dist = nums[0],ans = 1,value = nums[0];
        if(nums.size() == 1)
        return 0;
        
        for(int i=1 ; i < nums.size() ; i++){
            if(i == value+1){
                ans++;
                value = max_dist;
            }
            max_dist = max(max_dist,i+nums[i]);
        }

        return ans;
    }
};