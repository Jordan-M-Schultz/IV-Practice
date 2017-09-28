#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unordered_map> // <Key,Val>
#include <vector> 
#include <array>
#include <stack>

using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* createLLHeap(void);
Node createLLStack(void); 
Node* createLL(int n);
void printLL(Node * head);
void pushback(Node * head, int val);
void removeDup(Node * head);
bool checkPallindrome(Node * head);
void appendList(Node * a , Node * b);
int main(){
	Node* a = createLL(2);
	Node* b = createLL(3);
	pushback(a,1);
	pushback(a,0);
	printLL(a);
	//removeDup(a);
	cout << checkPallindrome(a) << endl;
	
	appendList(a,b);
	printLL(a);
	
	int *p=0; 
	printf("%d",++p); 


	return 0;
	
}

void appendList(Node * a , Node * b){
	if(a != NULL && b != NULL)
	{
		while(a->next != NULL)
			a = a->next;
		a->next = b;
	}
}

bool checkPallindrome(Node * head){
	//1->2->X->2->X //if fast->next null then odd
	//1->2->X->3->X->1 //else even
	//check half, two runners, fast and slow
	Node* fast = head;
	Node* slow = head;
	int compare;
	std::stack<int> storage;
	storage.push(head->data);
	while(fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
			fast = fast->next->next;
			slow = slow->next;
			storage.push(slow->data);
	}//while
	if(fast->next == NULL){ //if odd number
		while(!storage.empty()){
			compare = storage.top();
			storage.pop();
			if(slow->data != compare)
				return false;
			slow = slow->next;
		}
		return true;
	}//if
	else
	{
		slow = slow->next;
		while(!storage.empty()){
			compare = storage.top();
			storage.pop();
			if(slow->data != compare)
				return false;
			slow = slow->next;
		}
		return true;

	}
	

}

void removeDup(Node * head){
	unordered_map<int, Node * > str;
	unordered_map<int, Node *>::const_iterator it;
	Node* prev = head;
	Node* current = head;
	while(current != NULL){
		it = str.find(current->data);
		if(it == str.end())//this node has not been inserted
		{
			str.insert(make_pair(current->data,current));
			prev = current;
		}
		else	//node with val has been inserted already
			prev->next = current->next;
		
		current = current->next;

	}//while
}

Node* createLL(int n){ //heap, notice pointer

	Node * head = new Node;
	head->data = 0;
	head->next = NULL;
	Node * current = head;

	for(int i = 1 ; i < n ; i++){
		Node * newnode = new Node;
		newnode->data = i;
		newnode->next = NULL;
		current->next = newnode;
		current = current->next;
	}
	return head;
}

void printLL(Node * head){
	while(head !=NULL){
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
}

void pushback(Node* head, int val){
	Node * ins = new Node;
	Node * current = head;
	ins->data = val;
	ins->next = NULL;

	while(current->next != NULL)
		current = current->next;

	current->next = ins;

	
}

/*
Node createLLStack(void){
	Node head;
	Node temp = head;
	for(int i = 0 ; i < 10 ; i++){
		Node nx;
		temp.data = i;
		temp.next = (Node*)nx;
		temp = temp.next;
	}
	return head;

}*/
