class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // unordered_map<int,vector<string>>adj;

        // for(int i=0 ; i < bank.size() ; i++){
        //     int changes = 0;
        //     for(int j=0 ; j < bank[i].size() ; j++){
        //         if(bank[i][j] != startGene[j])
        //         changes++;
        //     }

        //     adj[changes].push_back(bank[i]);
        // }

        queue<pair<string,int>>q;
        q.push({startGene,0});

        while(!q.empty()){
            string parent = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == 11){
                return -1;
            }

            for(auto ch:bank){
                int changes = 0;
                for(int i=0 ; i < ch.size(); i++){
                    if(ch[i] != parent[i])
                    changes++;
                }

                if(changes == 1){
                    q.push({ch,level+1});
                    if(ch == endGene)
                    return level+1;
                }
            }
        }

        return -1;
    }
};