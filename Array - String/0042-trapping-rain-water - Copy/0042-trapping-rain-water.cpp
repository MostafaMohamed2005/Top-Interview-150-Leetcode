class Solution {
public:
    int pre[20005]={},suf[20005]={};
    int trap(vector<int>& height) {
        int n = height.size(),ans = 0;
        for(int i=1 ; i <= n ; i++)
        pre[i] = max(pre[i-1],height[i-1]);

        for(int i=n ; i >= 1 ; i--)
        suf[i] = max(suf[i+1],height[i-1]);

        for(int i=0 ; i < n ; i++){
            int max_height = min(pre[i],suf[i+2]);
            ans += max(0,max_height - height[i]);
        }

        return ans;
    }
};