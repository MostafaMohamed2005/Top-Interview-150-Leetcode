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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans = nullptr,*shead=head,*src = nullptr;
        while(head != nullptr){
            if(head->val < x){
                if(ans == nullptr){
                    ListNode *node = new ListNode(head->val);
                    ans = node;
                    src = ans;
                }
                else{
                    ListNode *node = new ListNode(head->val);
                    ans -> next = node;
                    ans = ans -> next;
                }
            }

            head = head -> next;
        }

        head = shead;

        while(head != nullptr){
            if(head->val >= x){
                if(ans == nullptr){
                    ListNode *node = new ListNode(head->val);
                    ans = node;
                    src = ans;
                }
                else{
                    ListNode *node = new ListNode(head->val);
                    ans -> next = node;
                    ans = ans -> next;
                }
            }

            head = head -> next;
        }


        return src;
    }
};