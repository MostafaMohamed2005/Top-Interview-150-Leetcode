/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    unordered_map<int,Node*>m;
    void dfs(Node* node, int level){
        if(node == NULL)
        return;
        cout << node -> val << endl;
        if(m.contains(level))
        m[level]->next = node;
        m[level] = node, level++;

        Node* left = node -> left;
        Node* right = node -> right;
        
        dfs(left,level);
        dfs(right,level);
    }
    
    Node* connect(Node* root) {
        dfs(root,1);
        return root;
    }
};