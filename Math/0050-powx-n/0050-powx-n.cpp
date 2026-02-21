class Solution {
public:

    long double fastPower(long double base , long long power) {
        if (power == 0) return 1;
        if (power == 1) return base;
        long double halfPower = fastPower(base , power/2);
        long double ret = (halfPower * halfPower);
        if (power % 2)
            ret = (ret * base);
        return ret;
    }
    double myPow(double x, int n) {
        long double ans;
        long long pow = abs((long long)n);

        if(!n)
        return 1;

        ans = fastPower(x,pow);

        if(n < 0)
        ans = 1/ans;
        return ans;
    }
};