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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a="",b="";
        while(l1 != nullptr){
            a += ('0'+l1->val);
            l1 = l1 -> next;
        }

        while(l2 != nullptr){
            b += ('0'+l2->val);
            l2 = l2 -> next;
        }

        int n = (a.size() > b.size() ? a.size() - b.size() : b.size() - a.size());
        for(int i=0 ; i < n ; i++){
            if(a.size() > b.size())
            b += '0';
            else
            a += '0';
        }

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        n = a.size();
        string s = "";
        int rest = 0;
        //cout << a << "\n" << b << endl;
        for(int i = n-1 ; i >= 0 ; i--){
            int val = (a[i]-'0')+(b[i]-'0')+rest;
            if(val >= 10)
            rest=1,val -= 10;
            else
            rest = 0;
            s += ('0'+val);
            //cout << val << endl;
        }

        if(rest)
        s += '1';

        //cout << s << endl;
        ListNode* ans = new ListNode();
        ListNode* node = ans;
        for(int i=0 ; i < s.size() ; i++){
            node->val = (int)(s[i] - '0');
       
            if(i != s.size()-1){
                ListNode* nex = new ListNode();
                node -> next = nex;
                node = node -> next;
            }
        }

        return ans;
    }
};