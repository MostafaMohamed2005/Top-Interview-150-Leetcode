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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        ListNode* pre = nullptr;

        while(head != nullptr){
            bool exist = false;
            int x = head -> val;
            ListNode *cur = head;
            head = head -> next;
            while(head != nullptr && head -> val == x){
                exist = true;
                head = head -> next;
            }

            if(exist){
                if(pre != nullptr)
                pre -> next = head;
                else
                ans = head;
            }else
            pre = cur;
        }


        return ans;
    }
};