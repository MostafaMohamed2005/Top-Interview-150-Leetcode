class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans = 0;
        for(int i=32 ; i >= 0 ; i--)
        {
            bool left_bit = ((long long)left >> i)&1;
            bool right_bit = ((long long)right >> i)&1;

            if((left_bit^right_bit))
            break;

            if(left_bit && right_bit)
            ans |= (1LL << i);
        }

        return ans;
    }
};

/*
    101
    111
*/