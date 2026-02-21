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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s_head = head;
        int cnt = 0;

        while(head != nullptr){
            head = head -> next;
            cnt++;
        }

        head = s_head;
        n = cnt - n + 1;

        if(n == 1){
            return head->next;
        }

        int index = 1;
        while(index++ != n-1){
            head = head -> next;
        }

        //cout << index << endl;
        ListNode* p = (head->next)->next;;
        head -> next = p;
        return s_head;
    }
};