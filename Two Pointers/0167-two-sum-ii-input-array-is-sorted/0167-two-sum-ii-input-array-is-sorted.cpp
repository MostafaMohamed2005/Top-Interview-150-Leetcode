class Solution {
public:
    vector<int>freq[5000];
    int constant = 2000;
    vector<int> twoSum(vector<int>& numbers, int target) {
        //cout << numbers[0] << endl;
        int n = numbers.size();
        vector<int>ans;
        

        for(int i=0 ; i < n ; i++){
            freq[numbers[i]+constant].push_back(i);
        }

        for(int i=0 ; i < n; i++){
            int second_value = target-numbers[i]+constant;
            //cout << second_value << endl;
            if(freq[second_value].empty())
            continue;

            int second_index = freq[second_value][0];
            if(second_index == i){
                if(freq[second_value].size() == 1)
                continue;
                second_index = freq[second_value][1];
            }

            ans = {i+1,second_index+1};
            break;
        }

        return ans;
    }
};