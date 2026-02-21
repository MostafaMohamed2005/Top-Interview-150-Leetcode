class Solution {
public:
    //  7 6 5 4 3 2 1 
    //  7 6 5 4 3 2 1 5 6 7 
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        for(int i=0 ; i < k ; i++)
        nums.push_back(nums[i]);
        reverse(nums.begin(),nums.end());
        for(int i=0 ; i < k ; i++)
        nums.pop_back();
    }
};