class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size() - 1,ans = 0;
        while(r > l){
            int cur_height = min(height[l],height[r]);
            ans = max(ans,cur_height*(r - l));
            if(height[r] > height[l])
            l++;
            else
            r--;
        }

        return ans;
    }
};


/*
    the bigger must stand 

    10 20 1 3
*/