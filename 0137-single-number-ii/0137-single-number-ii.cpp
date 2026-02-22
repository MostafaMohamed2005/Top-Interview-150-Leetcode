class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long bit_freq[33]={},negative = 0,min_int = -(1LL<<31),cnt_min_int=0;
        for(int i=0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                negative++;
                if(nums[i] != min_int)
                nums[i] = ~(nums[i]-1);
                else
                cnt_min_int++;
            }
            for(int j=0 ; j <= 30 ; j++){
                if((nums[i] >> j)&1){
                    bit_freq[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0; i <= 30 ; i++){
            if(bit_freq[i]%3 != 0)
            ans |= (1 << i);
        }

        if(negative%3 != 0)
        ans = -ans;
        if(cnt_min_int == 1)
        ans = min_int;

        return ans;
    }
};