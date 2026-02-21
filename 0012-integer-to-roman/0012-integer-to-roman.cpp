class Solution {
public:
    string intToRoman(int num) {
        int x = num;
        string ans = "";
        while(x >= 1000)
        ans.push_back('M'),x -= 1000;

        if(x/100 == 4)
        ans+= "CD",x -= 400;

        if(x/100 == 9)
        ans += "CM",x -= 900;

        while(x >= 500)
        ans.push_back('D'),x -= 500; 

        while(x >= 100)
        ans.push_back('C'),x -= 100;

        if(x/10 == 4)
        ans += "XL",x -= 40;

        if(x/10 == 9)
        ans += "XC",x -= 90;

        while(x >= 50)
        ans.push_back('L'),x -= 50;

        while(x >= 10)
        ans.push_back('X'),x -= 10;

        if(x == 4)
        ans += "IV",x -= 4;

        if(x == 9)
        ans += "IX",x -= 9;

        while(x >= 5)
        ans.push_back('V'),x -= 5;

        while(x >= 1)
        ans.push_back('I'),x--;

        return ans;
    }
};