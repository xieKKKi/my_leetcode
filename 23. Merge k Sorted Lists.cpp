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

    //归并法，时间复杂度knlogn
    ListNode *merge(vector<ListNode*>& lists, int left, int right){
        if(left > right)
            return NULL;
        if(left == right)
            return lists[left];
        if(left+1 == right)
            return mergeTwoLists(lists[left], lists[right]);

        int mid = (left+right) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};
