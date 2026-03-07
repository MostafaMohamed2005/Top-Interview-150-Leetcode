class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        int sum = 0,ans = -1e9;

        for(int i=0 ; i < n ; i++)
        nums.push_back(nums[i]);

        n *= 2;
        for(int i=0 ; i < n ; i++){
            sum += nums[i];
            ans = max(ans,sum);
            r = i;
            //cout << sum << endl;
            if(sum < 0)
            sum = 0,l = i+1;
            else{ 
                if(r - l + 1 == n/2){
                    int best_sum = sum-nums[l],new_l = l+1,new_sum=sum-nums[l];
                    for(int j=l+1 ; j <= r ; j++){
                        new_sum -= nums[j];
                        if(new_sum >= best_sum){
                            best_sum = new_sum;
                            new_l = j+1;
                        }
                    }

                    l = new_l;
                    sum = best_sum;
                    ans = max(ans,sum);
                }
            }
        }

        return ans;
    }
};