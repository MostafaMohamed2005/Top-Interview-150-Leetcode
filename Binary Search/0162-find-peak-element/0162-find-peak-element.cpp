class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(),l=0,r=n-1,ans = n-1;
        if(nums.size() == 1)
        return 0;

        while(r > l){
            int mid = (l+r)/2;
            if(nums[mid] > nums[mid+1])
            r = mid,ans = mid;
            else
            l = mid + 1;
        }

        return ans;
    }
};