#include<iostream>

using namespace std;

bool DEBUG = true;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head){
	if(head == NULL){
		cout<<"empty node"<<endl;
		return;
	}
	while(head->next != NULL){
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<head->val<<endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	//we know l1 and l2 are not NULL
	ListNode* curr = new ListNode(-1);//initialize listNode
	ListNode* head = curr;//what is returned
	int overflow = 0;
	while(l1 != NULL || l2 != NULL){
		if(DEBUG) print(head);
		int val1 = 0, val2 = 0;//val1 is what to add from l1 and val2 is what to add from l2
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
		if(DEBUG){
			cout<<"overflow: "<<overflow<<endl;
			print(head);
			cout<<endl;
		}
		if(DEBUG) print(head);
	}
	if(overflow != 0){
		ListNode* tmp = new ListNode(overflow);
		curr->next = tmp;
	}
	if(DEBUG) cout<<"end"<<endl;
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

	//ListNode* node1 = new ListNode(3);
	//ListNode* node2 = new ListNode(4);
	node2->next = node1;
	node1 = new ListNode(2);
	node1->next = node2;
	ListNode *head1 = node1;

	node1 = new ListNode(4);
	node2 = new ListNode(6);
	node2->next = node1;
	node1 = new ListNode(5);
	node1->next = node2;
	ListNode *head2 = node1;

	cout<<"Adding:"<<endl;
	print(head1);
	print(head2);

	addTwoNumbers(head1, head2);
}
