class Solution {
public:
    int freq[1000000]={};
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int mid = 4e5;

        for(int i=0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1])
            continue;

            for(int j=i+1 ; j < nums.size() ; j++)
            freq[nums[j]+mid]++;

            for(int j=i+1 ; j < nums.size() ; j++){
                freq[nums[j]+mid]--;
                if(j > i+1 && nums[j] == nums[j-1])
                continue;

                int rest = -(nums[i] + nums[j])+mid;
                if(freq[rest])
                ans.push_back({nums[i],nums[j],-(nums[i]+nums[j])});
            }
        }


        return ans;
    }
};