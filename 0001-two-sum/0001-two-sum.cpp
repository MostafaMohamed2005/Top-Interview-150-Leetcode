class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0 ; i < nums.size() ; i++){
            m[nums[i]]=i+1;
        }

        for(int i=0 ; i < nums.size() ; i++){
            int x = target - nums[i];
            if(m[x] != 0 && m[x] != i+1)
            return {i,m[x]-1};
        }

        return {-1,-1};
    }
};