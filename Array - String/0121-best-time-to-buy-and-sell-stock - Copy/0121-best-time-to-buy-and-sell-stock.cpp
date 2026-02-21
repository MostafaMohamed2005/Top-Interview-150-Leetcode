class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int>suf(prices.size());
       suf[prices.size() - 1] = prices.back();
       for(int i=prices.size() - 2 ; i >= 0 ; i--)
       suf[i] = max(prices[i],suf[i+1]);

        int ans = 0;
       for(int i=0 ; i < prices.size() - 1 ; i++){
            ans = max(ans,suf[i+1]-prices[i]);
       }

       return ans;
    }
};