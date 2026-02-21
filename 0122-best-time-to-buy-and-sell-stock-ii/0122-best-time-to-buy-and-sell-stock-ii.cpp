class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = prices[0],ans = 0;
        for(int i=1 ; i < prices.size() ; i++){
            if(prices[i] < prices[i-1]){
                ans += max(0,prices[i-1] - cur);
                cur = prices[i];
            }
        }

        ans += max(0,prices.back() - cur);

        return ans;
    }


};


/*
    1 2 3 4 3 10
*/