#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){
	ListNode *tmp = head;
	while(tmp->next != NULL){
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<tmp->val<<endl;
}

void mergeTwoLists(ListNode* l1, ListNode* l2){
	cout<<"Called"<<endl;
	printList(l1);
	printList(l2);
}

int main(){
	cout<<"Making listnodes"<<endl;
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(4);
	node1->next = node2;
	node2 = node1;
	node1 = new ListNode(1);
	node1->next = node2;
	ListNode *head1 = node1;

	node1 = new ListNode(1);
	ListNode *head2 = node1;
	node2 = new ListNode(3);
	node1->next = node2;
	node1 = new ListNode(4);
	node2->next = node1;

	mergeTwoLists(head1, head2);
}
