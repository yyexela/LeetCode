#include<iostream>

using namespace std;

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

void addTwoNumbers(ListNode* l1, ListNode* l2){

}

int main(){
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(4);
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
}
