class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a = nums[0],cnt_a = 1,b = nums[0],cnt_b = 1,le = 1,cur_num=nums[0];

        for(int i=1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                le++;
            }else{
                if(le > cnt_a)
                cnt_a = le,a = cur_num;
                else if(le <= cnt_a){
                    if(le >= cnt_b)
                    cnt_b = le,b = cur_num;
                }
                le = 1,cur_num = nums[i];
            }
        }

        if(le > cnt_a)
        cnt_a = le,a = cur_num;
        else if(le <= cnt_a){
            if(le >= cnt_b)
            cnt_b = le,b = cur_num;
        }

        cnt_a = 0,cnt_b = 0;
        for(int i=0 ; i < nums.size() ; i++){
            if(nums[i] == a)
            cnt_a++;
            else if(nums[i] == b)
            cnt_b++;
        }

        return (cnt_a >= cnt_b ? a : b);
    }
};

/* 
    2 3 3 3 2 
    2 3 3 2 3 
    2 3 2 3 3
    2 2 3 3 3
    3 3 2 2 3
    3 2 3 2 3
*/