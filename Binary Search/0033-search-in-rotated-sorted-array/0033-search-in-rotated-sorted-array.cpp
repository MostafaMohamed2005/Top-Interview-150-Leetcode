class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool one = false, two = false;
        if(nums.front() > nums.back()){
            if(target > nums.back())
            one = true;
            else
            two = true;
        }

        int l = 0, r = nums.size()-1;
        while(r >= l){
            int mid = (l+r)/2;
            if(nums[mid] == target)
            return mid;

            if(one){
                if(nums[mid] >= nums.front()){
                    if(target > nums[mid])
                    l = mid + 1;
                    else
                    r = mid - 1;
                }
                else
                r = mid - 1;
            } 
            else if(two){
                if(nums[mid] < nums.front()){
                    if(target > nums[mid])
                    l = mid + 1;
                    else
                    r = mid - 1;
                }
                else
                l = mid + 1;
            }else{
                if(target > nums[mid])
                l = mid + 1;
                else
                r = mid - 1;
            }
            //cout << l << " " << r << endl;
        }

        return -1;
    }
};