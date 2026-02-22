class Solution {
public:
    int reverseBits(int n) {
        long long ans = 0;
        long long x = n;
        for(int i=0 ; i <= 31 ; i++){
            if(((x >> i)&1))
            ans += (1LL << (31-i));
        }

        return ans;
    }
};