class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        vector<double>ans;

        for(int i=0 ; i < equations.size() ; i++){
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b,values[i]});
            adj[b].push_back({a,1/values[i]});
        }

        for(int i=0 ; i < queries.size() ; i++){
            string a = queries[i][0];
            string b = queries[i][1];

            if(!adj.contains(a) || !adj.contains(b)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_map<string,double>vis;
            queue<string>q;
            q.push(a);
            vis[a] = 1;
            while(!q.empty()){
                string parent = q.front();
                q.pop();

                for(auto [ch,value]:adj[parent]){
                    if(!vis.contains(ch)){
                        vis[ch] = vis[parent]*value;
                        q.push(ch);
                    }
                }
            }

            if(!vis.contains(b))
            ans.push_back(-1.0);
            else
            ans.push_back(vis[b]);
        }

        return ans;
    }
};