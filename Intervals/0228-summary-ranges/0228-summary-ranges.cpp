class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l=0,r=0;
        vector<string>ans;
        if(nums.empty())
        return ans;
        for(int i=1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]+1)
            r++;
            else {
                if(l == r){
                    string s = to_string(nums[l]);
                    //cout << s << endl;
                    ans.push_back(s);
                }
                else{
                    string s = to_string(nums[l])+"->"+to_string(nums[r]);
                    //cout << s << endl;
                    ans.push_back(s);
                }

                l = r = i;
            }
        }

        if(l == r){
            string s = to_string(nums[l]);
            //cout << s << endl;
            ans.push_back(s);
        }
        else{
            string s = to_string(nums[l])+"->"+to_string(nums[r]);
            //cout << s << endl;
            ans.push_back(s);
        }

        return ans;
    }
};