class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool increment = true;
        for(int i=n-1; i >= 0 ; i--){
            if(increment){
                if(digits[i] == 9)
                digits[i] = 0;
                else
                digits[i]++,increment = false;
            }
        }

        if(!increment)
        return digits;
        else{
            vector<int>ans = {1};
            for(int i=0 ; i < n ; i++)
            ans.push_back(digits[i]);
            return ans;
        }
    }
};