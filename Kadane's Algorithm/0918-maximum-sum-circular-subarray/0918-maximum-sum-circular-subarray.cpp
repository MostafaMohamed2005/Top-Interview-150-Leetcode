class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,max_array = -1e9,min_array = 1e9,total = 0,pos = 0;
        for(int i=0 ; i < n ; i++){
            sum += nums[i];
            total += nums[i];
            if(nums[i] > 0)
            pos = 1;
            max_array = max(max_array,sum);
            if(sum < 0)
            sum = 0;
        }

        sum = 0;
        for(int i=0 ; i < n ; i++){
            sum += nums[i];
            min_array= min(min_array,sum);
            if(sum >= 0)
            sum = 0;
        }

        //cout << max_array << " " << min_array << endl;
        if(!pos)
        return max_array;

        return max(max_array,total - min_array);
    }
};