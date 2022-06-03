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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* lastOdd = head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(odd && even){
            if(odd->next)
            {
                lastOdd = odd;
                odd->next = odd->next->next;
                odd = odd->next;
            }
            if(even->next)
                even->next = even->next->next;
                even = even->next;
        }
        if(odd)
            odd->next = evenHead;
        else
            lastOdd->next = evenHead;
        return head;
    }
};
