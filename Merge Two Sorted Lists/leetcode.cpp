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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *tmp1 = l1, *tmp2 = l2, *head;
        //set l1 to the lowest value head
        if(l2->val < l1->val) l1 = l2;
        head = l1;
        while(tmp1 != NULL && tmp2 != NULL){
                if(tmp1 == l1) tmp1 = tmp1->next;
                else if(tmp2 == l1) tmp2 = tmp2->next;
                //check which number goes next
                if(tmp2 == NULL && tmp1 != NULL) l1->next = tmp1;
                else if (tmp1 == NULL && tmp2 != NULL) l1->next = tmp2;
                else if(tmp2->val - l1->val <= tmp1->val - l1->val){
                        l1->next = tmp2;
                        l1 = l1->next;
                } else if (tmp1 != NULL) {
                        l1->next = tmp1;
                        l1 = l1->next;
                }
            }
            return head;
        }
};
