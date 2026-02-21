class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 1, r = nums.size()-1,mi = nums[0];

        while(r >= l){
            int mid = (l+r)/2;
            if(nums[mid] > mi){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                mi = min(mi,nums[mid]);
            }
        }

        return mi;
    }
};