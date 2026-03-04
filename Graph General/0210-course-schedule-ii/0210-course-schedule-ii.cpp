class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int in_freq[2002]={},n = numCourses,m = prerequisites.size();
        vector<int>adj[2002],ans;


        for(int i=0 ; i < m ; i++){
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];

            in_freq[b]++;
            adj[a].push_back(b);
        }

        queue<int>q;    
        for(int i=0 ; i < n ; i++){
            if(!in_freq[i])
            q.push(i),ans.push_back(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto ch:adj[node]){
                in_freq[ch]--;
                if(!in_freq[ch]){
                    q.push(ch);
                    ans.push_back(ch);
                }
            }
        }

        if(ans.size() != n)
        return {};

        return ans;
    }
};