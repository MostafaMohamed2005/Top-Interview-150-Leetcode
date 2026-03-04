/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>vis;
    Node* ans = nullptr,*x = ans;

    void solve(Node* node){

        vis[node->val] = node;
        vector<Node*>v = (ans->neighbors);
        vector<Node*>new_v;

        if(x == nullptr)
        x = node;

        for(int i=0 ; i < v.size() ; i++){
            if(!vis[v[i]->val]){
                Node* new_node = new Node(v[i]->val);
                new_v.push_back(new_node);
                ans = v[i];
                solve(new_node);
            }else{
                new_v.push_back(vis[v[i]->val]);
            }
        }

        node->neighbors = new_v;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
        return node;

        ans = node;
        Node* new_node = new Node(1);
        solve(new_node);

        return x;
    }
};

/*
    create all nodes
*/