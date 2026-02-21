class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>pos;
        for(int i=0 ; i < nums.size() ; i++){
            if(pos[nums[i]] && i+1-pos[nums[i]] <= k)
            return true;
            pos[nums[i]] = i+1;
        }

        return false;
    }
};