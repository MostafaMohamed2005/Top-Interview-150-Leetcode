class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        long long ans = w,index = 0,n = profits.size();
        vector<pair<long long,long long>>v;
        multiset<long long>m;

        for(int i=0 ; i < n ; i++)
        v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());

        bool next = true;
        while(k > 0 && next){
            next = false;
            while(n > index && ans >= v[index].first)
            m.insert(v[index].second),index++,next = true;

            if(k > 0 && !m.empty()){
                auto it = m.end();
                it--;
                ans += *it;
                k--;
                m.erase(it);
                next = true;
            }
        }

        return ans;
    }
};

/*
    k distinct projects
    n projects -> profit, capital(to start it)
    w capital
    best for me -> max difference that have capital <= current_capital
*/