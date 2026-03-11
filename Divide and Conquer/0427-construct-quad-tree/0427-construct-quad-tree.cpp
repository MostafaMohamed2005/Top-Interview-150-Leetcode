/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int n;
    Node* solve(int x, int y, int size,vector<vector<int>>& grid){
        int zero = 0,one = 0;
        for(int i=x ; i <= x+size-1 ; i++){
            for(int j=y ; j <= y+size-1 ; j++){
                grid[i][j] == 0 ? zero++ : one++;
            }
        }

        if(zero == size*size)
        return (new Node(0,1));
        else if(one == size*size)
        return (new Node(1,1));
        else{
            Node* ans = new Node();
            ans -> topLeft = solve(x,y,size/2,grid);
            ans -> topRight = solve(x,y+size/2,size/2,grid);
            ans -> bottomLeft = solve(x+size/2,y,size/2,grid);
            ans -> bottomRight = solve(x+size/2,y+size/2,size/2,grid);
            return ans;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        return solve(0,0,n,grid);
    }
};

/*
    each grid -> x1,x2,y1,y2
*/