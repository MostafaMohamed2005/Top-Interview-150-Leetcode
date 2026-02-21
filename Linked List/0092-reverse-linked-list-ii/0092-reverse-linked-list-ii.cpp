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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode *node = nullptr,*s_head = head;
        int index = 1;
        while(index <= right){
            if(index == left)
            node = head;
            if(index >= left)
            v.push_back(head->val);
            head = head -> next;
            index++;
        }

        index = left;
        while(index <= right){
            node->val = v.back();
            v.pop_back();
            node = node -> next;
            index++;
        }

        return s_head;
    }
};