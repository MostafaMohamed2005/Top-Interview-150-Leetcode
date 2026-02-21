class Solution {
public:
    int n;
    pair<int,int>position(int number){
        int row = (number-1)/n;
        int col = (number-1)%n;
        if(row%2 == 1)
        col = (n-1)-col;
        row = (n-1)-row;
    
        return {row,col};
    }

    int vis[25][25];
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        n = board.size();
        for(int i=0 ; i < 25 ; i++)
        for(int j=0 ; j < 25 ; j++)
        vis[i][j] = 1e9;

        q.push(1);
        vis[n-1][0] = 0;
        while(!q.empty()){
            int node = q.front();
            pair<int,int>cur_pos = position(node);
            q.pop();
            //cout << node << " " << cur_pos.first << " " << cur_pos.second << endl;

            
            for(int i=node+1 ; i <= min(node+6,n*n) ; i++){
                pair<int,int>pos = position(i);
                int value = i;
                if(board[pos.first][pos.second] != -1){
                    value = board[pos.first][pos.second];
                    pos = position(value);
                }
                
                if(vis[pos.first][pos.second] == 1e9){
                    vis[pos.first][pos.second] = vis[cur_pos.first][cur_pos.second]+1;
                    q.push(value);
                }
                
            }
        }


        pair<int,int>pos = position(n*n);
        return (vis[pos.first][pos.second] == 1e9 ? -1 : vis[pos.first][pos.second]);
    }
};

/*

*/