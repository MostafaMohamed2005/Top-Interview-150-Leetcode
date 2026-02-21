class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        return s;

        vector<char>v[numRows+1];
        bool high = true,low = false;
        int index = 1;
        for(int i=0 ; i < s.size() ; i++){
            v[index].push_back(s[i]);
            if(high){
                index++;
                if(index == numRows+1)
                index = numRows-1,high=false,low=true;
            }else{
                index--;
                if(index == 0)
                index = 2,high=true,low=false;
            }
        }

        string ans = "";
        for(int i=1 ; i <= numRows ; i++){
            for(int j=0 ; j < v[i].size() ; j++){
                ans.push_back(v[i][j]);
            }
        }

        return ans;
    }
};