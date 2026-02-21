/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
        return NULL;

        Node* s_head = head;
        Node* ans = NULL;
        Node* src = NULL;

        unordered_map<Node*,int>pos;
    
        int cnt = 0;
        while(s_head != NULL){
            pos[s_head] = cnt++;
            s_head = s_head -> next;
        }

        pos[s_head] = cnt;

        s_head = head;
        unordered_map<int,Node*>new_pos;
        cnt = 0;
        while(head != NULL){
            Node* node = new Node(head->val);
            node->next = head-> next;
            if(ans == NULL)
            ans = node;
            else
            ans->next = node,ans=ans->next;
            if(src == NULL)
            src = ans;
            head=head->next;

            new_pos[cnt++] = ans;
        }

        ans = src;
        while(s_head != NULL){
            int index = pos[s_head->random];
            s_head = s_head -> next;
            Node *node = new_pos[index];
            ans->random = node;
            ans = ans->next;
        }

        return src;
    }
};