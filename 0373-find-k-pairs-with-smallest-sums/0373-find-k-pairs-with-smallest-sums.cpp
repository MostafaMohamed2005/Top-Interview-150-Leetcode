class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>>ans;
        multiset<pair<int,pair<int,int>>>m;

        for(int i=0 ; i < min((int)nums1.size(),k) ; i++)
        m.insert({nums1[i]+nums2[0],{i,0}});

        while(k--){
            pair<int,pair<int,int>>p = *m.begin();
            m.erase(m.begin());
            int i = p.second.first,j = p.second.second;
            
            ans.push_back({nums1[i],nums2[j]});
            j++;
            if(j < nums2.size())
            m.insert({nums1[i]+nums2[j],{i,j}});
        }

        return ans;
    }
};

/*

*/