/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(int l, int r, ListNode* node){
        if(l > r)
        return nullptr;

        if(l == r)
        return node;

        int mid = (l+r)/2;
        ListNode* same = node,*lastNode = node;
        int cnt = 0;
        while(cnt != mid - l + 1){
            if(cnt == mid - l)
            lastNode = same;
            same = same -> next;
            cnt++;
        }

        lastNode -> next = nullptr;
        
        ListNode* left = solve(l,mid,node); 
        ListNode* right = solve(mid+1,r,same);

        //cout << "values: " << left -> val << " " << right -> val << endl;

        ListNode* ans = nullptr,*x = nullptr;

        while(left != nullptr && right != nullptr){
            if(left -> val <= right -> val){
                if(ans == nullptr)
                ans = new ListNode(left->val),x = ans;
                else
                ans -> next = new ListNode(left->val),ans = ans -> next;
                left = left -> next;
            }else{
                if(ans == nullptr)
                ans = new ListNode(right->val),x = ans;
                else
                ans -> next = new ListNode(right->val),ans = ans -> next;
                right = right -> next;
            }

        
        }

        while(left != nullptr){
            if(ans == nullptr)
            ans = new ListNode(left->val),x = ans;
            else
            ans -> next = new ListNode(left->val),ans = ans -> next;
            left = left -> next;
        }

        while(right != nullptr){
            if(ans == nullptr)
            ans = new ListNode(right->val),x = ans;
            else
            ans -> next = new ListNode(right->val),ans = ans -> next;
            right = right -> next;
        }

        return x;
    }

    ListNode* sortList(ListNode* head) {
        int cnt = 0;
        ListNode *node = head;
        while(node != nullptr)
        node = node -> next,cnt++;

        ListNode* ans = solve(0,cnt-1,head);
        return ans;
    }
};