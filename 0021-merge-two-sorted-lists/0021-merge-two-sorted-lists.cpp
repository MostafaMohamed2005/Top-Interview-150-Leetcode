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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = nullptr;
        ListNode *src = nullptr;
     
        while(list1 != nullptr && list2 != nullptr){
            //cout << list1 -> val << " " << list2 -> val << endl;
            if(list1 -> val <= list2 -> val){
                if(ans == nullptr)
                ans = list1,src = ans;
                else
                ans -> next = list1,ans = ans -> next;
                list1 = list1 -> next;
            }else{
                if(ans == nullptr)
                ans = list2,src = ans;
                else
                ans -> next = list2,ans = ans -> next;
                list2 = list2 -> next;
            } 
        }

        while(list1 != nullptr){
            cout << list1 -> val << endl;
            if(ans == nullptr)
            ans = list1,src=ans;
            else
            ans -> next = list1,ans = ans -> next;

            list1 = list1 -> next;
            
        }

        while(list2 != nullptr){
            cout << list2 -> val << endl;

            if(ans == nullptr)
            ans = list2,src =ans;
            else
            ans -> next = list2,ans = ans -> next;;
            list2 = list2 -> next;

        }

        return src;
    }
};