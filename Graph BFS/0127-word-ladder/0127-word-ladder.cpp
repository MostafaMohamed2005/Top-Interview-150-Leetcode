class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>vis;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord] = 1;

        while(!q.empty()){
            string parent = q.front();
            q.pop();

            for(auto ch:wordList){
                int changes = 0;
                for(int i=0 ; i < ch.size(); i++){
                    if(ch[i] != parent[i])
                    changes++;
                }

                if(changes == 1 && !vis.contains(ch)){
                    q.push(ch);
                    vis[ch] = vis[parent]+1;
                    if(ch == endWord)
                    return vis[ch];
                }
            }
        }

        return 0;
    }
};