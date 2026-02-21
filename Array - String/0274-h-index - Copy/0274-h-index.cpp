class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(),citations.end());

        for(int i=0 ; i < citations.size() ; i++){
            ans = max(ans,min(citations[i],(int)citations.size() - i));
        }

        return ans;
    }
};

/*

*/