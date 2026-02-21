class Solution {
public:
    int mySqrt(int x) {
        long long l=0,r=x,ans = 0,y = x;
        while(r >= l){
            long long mid = (l+r)/2;
            if(mid*mid <= y){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return (int)ans;
    }
};