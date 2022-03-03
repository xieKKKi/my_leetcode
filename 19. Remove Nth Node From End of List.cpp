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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *dummy = new ListNode(0, head);  //下一个节点是头节点的指针，处理头节点要被删除的情况
    //     ListNode *first = head;
    //     ListNode *second = dummy;

    //     for(int i=0;i<n;++i){  //first先走n步
    //         first = first->next;
    //     }

    //     while(first){  //fisrt走到尾部，此时second的下一个节点就是要删除的节点
    //         first = first->next;
    //         second = second->next;
    //     }

    //     //没有delete
    //     second->next = second->next->next;
    //     return dummy->next;
    // }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *p = head;
        while(p){   //数数有几个节点
            p = p->next;
            ++count;
        }

        count = count - n;  //要删除第count个节点
        if(count == 0)
            return head->next;
        
        p = head;
        while(count != 1){
            p = p->next;
            --count;
        }
        ListNode *q = p->next;
        p->next = p->next->next;
        delete q;
        return head;
    }
};
