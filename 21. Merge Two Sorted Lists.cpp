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
    //递归实现
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        else if(!list2)
            return list1;

        ListNode *head;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        head->next = mergeTwoLists(list1, list2);
        return head;
    }

    //迭代实现
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if(!list1)
    //         return list2;
    //     else if(!list2)
    //         return list1;
        
    //     ListNode *head, *p;
    //     if(list1->val <= list2->val){
    //         head = list1;
    //         p = head;
    //         list1 = list1->next;
    //     }
    //     else{
    //         head = list2;
    //         p = head;
    //         list2 = list2->next;
    //     }

    //     while(list1 && list2){
    //         if(list1->val <= list2->val){
    //         p->next = list1;
    //         p = p->next;
    //         list1 = list1->next;
    //     }
    //         else{
    //             p->next = list2;
    //             p = p->next;
    //             list2 = list2->next;
    //         }
    //     }
    //     while(list1){
    //         p->next = list1;
    //         p = p->next;
    //         list1 = list1->next;
    //     }
    //     while(list2){
    //         p->next = list2;
    //         p = p->next;
    //         list2 = list2->next;
    //     }
    //     return head;
    // }
};
