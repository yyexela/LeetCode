#include<iostream>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* curr = new ListNode(-1);//initialize listNode
        ListNode* head = curr;//what is returned
        int overflow = 0;
        while(l1 != NULL || l2 != NULL){
                int val1 = 0, val2 = 0;
                if(l1 != NULL){
                        val1 = l1->val;
                        l1 = l1->next;
                }
                if(l2 != NULL){
                        val2 = l2->val;
                        l2 = l2->next;
                }
                ListNode* tmp = new ListNode((overflow + val1 + val2)%10);
                overflow = (val1 + val2 + overflow)/10;
                curr->next = tmp;
                curr = tmp;
        }
        if(overflow != 0){
                ListNode* tmp = new ListNode(overflow);
                curr->next = tmp;
        }
        return head->next;
}

int main(){

	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(8);
	node1->next = node2;
	node2 = new ListNode(0);
	print(node2); print(node1); cout<<endl;
	print(addTwoNumbers(node1, node2));
	return 0;
}
