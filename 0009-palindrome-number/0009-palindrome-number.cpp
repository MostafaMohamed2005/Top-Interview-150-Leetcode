class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        return false;

        long long y = x,base1=10,base2=10;
        while(y >= base1*10)
        base1*=10;

        if(x >= 0 && x <= 9)
        return true;
        while(base1 >= base2 && x && y){
            int digit1 = x/base1;
            x -= digit1*base1;
            base1 /= 10;
            int digit2 = y%10;
            y /= 10;


            cout << digit1 << " " << digit2 << endl;

            if(digit1 != digit2)
            return false;
        }

        return true;
    }
};

/*
    535 -
*/