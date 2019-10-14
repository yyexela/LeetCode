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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	bool DEBUG = true;
	if(DEBUG) cout<<"Called"<<endl;
	if(DEBUG) printList(l1);
	if(DEBUG) printList(l2);
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	ListNode *tmp1 = l1, *tmp2 = l2, *head;
	//set l1 to the lowest value head
	if(l2->val < l1->val) l1 = l2;
	head = l1;
	while(tmp1 != NULL && tmp2 != NULL){
		if(DEBUG) cout<<"looping"<<endl;
		if(DEBUG) cout<<"list: ";
		if(DEBUG) printList(head);
		if(DEBUG) cout<<"l1: "<<l1->val<<" tmp1: "<<tmp1->val<<" tmp2: "<<tmp2->val<<endl;
		if(tmp1 == l1){
			tmp1 = tmp1->next;
			if(DEBUG) cout<<"moving tmp1"<<endl;
		}
		else if(tmp2 == l1){
			tmp2 = tmp2->next;
			if(DEBUG) cout<<"moving tmp2"<<endl;
		}
		//check which number goes next
		if(tmp2 == NULL && tmp1 != NULL){
			//set l1 to tmp1
			l1->next = tmp1;
		} else if (tmp1 == NULL && tmp2 != NULL){
			//set l1 to tmp2
			l1->next = tmp2;
		} else if(tmp2->val - l1->val <= tmp1->val - l1->val){
			l1->next = tmp2;
			l1 = l1->next;
		} else if (tmp1 != NULL) {
			//tmp1->val > tmp2->val || tmp2 == NULL
			l1->next = tmp1;
			l1 = l1->next;
		}
		if(DEBUG) printList(head);
	}
	if(DEBUG) printList(head);
	return head;
}

int main(){
	cout<<"Making listnodes"<<endl;
	/*
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
	*/
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(1);


	mergeTwoLists(node1, node2);
}
