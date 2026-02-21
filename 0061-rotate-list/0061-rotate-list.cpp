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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* ans = head;
        int cnt = 0;
        while(ans != nullptr){
            ans = ans -> next;
            cnt++;
        }

        if(!cnt)
        return head;
        
        k = cnt - (k%cnt);
        if(k == cnt)
        return head;

        int index = 1;
        ListNode *cur = nullptr, *last = head;
        ans = head;
        while(index != cnt){
            if(index == k)
            cur = last;

            last = last -> next;
            index++;
        }

        //cout << last->val << endl;
        ans = cur->next;
        cur->next = nullptr;
        last->next = head;

        return ans;
    }
};