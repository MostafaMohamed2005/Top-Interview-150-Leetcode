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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head,*pre = nullptr,*s_head = head,*ans = nullptr;
        while(true){
            int cnt = 0;
            while(s_head != nullptr && cnt != k)
            s_head = s_head -> next, cnt++;

            if(cnt != k){
                if(pre == nullptr)
                return head;
                else{
                    pre->next = head;
                }
                break;
            }

            ListNode* group = new ListNode(head->val);
            head = head -> next;
            for(int i=0 ; i < k-1 ; i++){
                ListNode* node = new ListNode(head->val);
                head = head -> next;
                node -> next = group;
                group = node; 
            }

            if(ans == nullptr)
            ans = group;

            ListNode *last = group;
            while(last->next != nullptr){
                last = last->next;
            }

            if(pre == nullptr)
            pre = last;
            else{
                pre->next = group;
                pre = last;
            }
        }

        return ans;
    }
};