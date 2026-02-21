class Solution {
public:

    int value(char x){
        if(x == 'I')
        return 1;
        else if(x == 'V')
        return 5;
        else if(x == 'X')
        return 10;
        else if(x == 'L')
        return 50;
        else if(x == 'C')
        return 100;
        else if(x == 'D')
        return 500;
        else
        return 1000;
    }
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0 ; i < s.size() ; i++){
            ans += value(s[i]);
            if(i > 0 && value(s[i]) > value(s[i-1]))
            ans -= value(s[i-1])*2;
        }
        return ans;
    }
};

/*

*/