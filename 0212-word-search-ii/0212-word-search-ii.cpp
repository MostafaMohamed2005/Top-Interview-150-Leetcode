class Solution {
public:

    struct node{
        int exist[26]={};
    };

    vector<node>trie;
    
    
    void insert(string word) {
        int cur_level = 0;

        for(int i=0 ; i < word.size() ; i++){

            int x = word[i]-'a';

            if(!trie[cur_level].exist[x]){
                trie[cur_level].exist[x] = trie.size();
                cur_level = trie.size();
                trie.emplace_back();
            }else{
                cur_level = trie[cur_level].exist[x];
            }
        }
    }

    bool startsWith(string prefix) {
        int cur_level = 0;

        for(int i=0 ; i < prefix.size() ; i++){
            int x = prefix[i]-'a';
            if(!trie[cur_level].exist[x])
            return false;
            
            cur_level = trie[cur_level].exist[x];
        }   

        return true;
    }

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[15][15]={};
    int n,m;

    bool valid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void solve(int i, int j, string &s, vector<vector<char>>& board){
        //cout << s << endl;
        if(s.size() == min(10,n*m)){
            insert(s);
            return;
        }


        bool change = false;
        vis[i][j] = true;

        for(int z=0 ; z < 4 ; z++){
            int x = i + dx[z];
            int y = j + dy[z];
            if(valid(x,y) && !vis[x][y]){
                s.push_back(board[x][y]);
                solve(x,y,s,board);
                s.pop_back();
                change = true;
            }
        }

        vis[i][j] = false;
        if(!change){
            insert(s);
        }
    }   

    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(),m = board[0].size();
        trie.emplace_back();

        for(int i=0 ; i < n ; i++){
            for(int j=0 ; j < m ; j++){
                string s = "";
                s.push_back(board[i][j]);
                solve(i,j,s,board);
            }
        }

        vector<string>ans;
        for(int i=0 ; i < words.size() ; i++){
            if(startsWith(words[i])){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};