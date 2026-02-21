class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l_n[100006]={};
        int ma = 0,ans = 0,total = 0;
        for(int i=prices.size()-1 ; i >= 0 ; i--)
        {
            ma = max(ma,prices[i]);
            ans = max(ans,ma - prices[i]);
            l_n[i] = max(l_n[i+1],ans);
        }

        int mi = 1e9;
        ans = 0;
        for(int i=0 ; i < prices.size() ; i++)
        {
            mi = min(mi,prices[i]);
            ans = max(ans,prices[i]-mi);
            total = max(total,ans + l_n[i+1]);
        }

        return total;
    }
};

/*

*/