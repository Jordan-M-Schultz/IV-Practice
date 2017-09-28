#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unordered_map> // <Key,Val>
#include <vector> 
#include <array>
#include <stack>
#include <set>


struct Node{
	int data;
	Node*right;
	Node*left;

};

void insert(Node* head, int num);	
Node* createtree(int total);
void levelorder(Node* head);
void preorder(Node * head);
void postorder(Node * head);
Node* newNode(int d){
	Node * te = new Node;
	te->data = d;
	te->left = NULL;
	te->right = NULL;
	return te;
}

using namespace std;
int main(){

/*	std::vector<int> v; //not sorted, specific
	std::set<int> s; //keeps sorted

	s.insert(5);
	s.insert(4);

	v.push_back(5);
	v.push_back(4);
	for(auto it = v.begin(); it != v.end() ; it++){
		cout << *it << endl;
	}
	cout << v[0];
	v[0] = 2;
	cout << v[0];
*/
	Node * root = new Node;
	root->data = 1;
     root->left      = newNode(2);
     root->right     = newNode(3);
     root->left->left  = newNode(4);
     root->left->right   = newNode(5); 


//	newroot = createtree(5);
	levelorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	return 0;
}

void levelorder(Node* head){
	if(head == NULL)
		return;
	levelorder(head->left);
	cout << head->data << " ";
	levelorder(head->right);

}
void preorder(Node * head){
	if(head == NULL)
		return;
	cout << head->data << " ";
		preorder(head->left);
		preorder(head->right);
}
void postorder(Node * head){
	if(head == NULL)
		return;
		postorder(head->left);
		postorder(head->right);
		cout << head->data << " ";
	
}

Node* createtree(int total){
	Node* root = new Node;
	root->data = (total/2)+1;
	root->left = NULL;
	root->right = NULL;

	for(int i = 0 ; i < total ; i++){
		if(i != ((total/2)+1))
			insert(root,i);
	}
	return root;
}

void insert(Node* head, int num){	
	if(num < head->data){
		if(head->left == NULL){
			Node * temp = new Node;
			temp->data = num;
			temp->left = NULL;
			temp->right = NULL;
			head->left = temp;
		}
		else
			insert(head->left, num);

	}
	else if(num > head->data)
	{
		if(head->right == NULL){
			Node * temp = new Node;
			temp->left = NULL;
			temp->right = NULL;
			temp->data = num;
			head->right = temp;
		}
		else
			insert(head->right, num);

	}
	else //head is null or no data given
		return;

}
