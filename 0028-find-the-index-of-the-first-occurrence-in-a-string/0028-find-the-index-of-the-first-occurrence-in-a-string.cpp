class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size(),size2=needle.size();
        for(int i=0 ; i < size1-size2+1 ; i++){
            //cout << i << endl;
            if(haystack.substr(i,needle.size()) == needle){
                return i;
            }
        }

        return -1;
    }
};