class Solution {
public:

    bool canJump(vector<int>& nums) {
        int max_dist = nums[0];

        for(int i=1 ; i < nums.size() ; i++){
            if(i > max_dist){
                return false;
            }

            max_dist = max(max_dist,i+nums[i]);
        }

        return true;
    }
};

/*

*/