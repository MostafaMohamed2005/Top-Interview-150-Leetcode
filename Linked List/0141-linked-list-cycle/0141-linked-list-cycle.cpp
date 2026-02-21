/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>exist;
        exist[head] = true;
        while(head != nullptr){
            head = head -> next;
            if(exist[head])
            return true;
            exist[head] = true;
        }

        return false;
    }
};