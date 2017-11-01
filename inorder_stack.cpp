//============================================================================
// Name        : inorder_stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
template <class X>

class stack
{
	X* a;
	int top;
	int size;
	int cap;
public:
stack(int s)
{
	//struct stack* n=new stack();
	top=-1;
	a=new X[s];
	size=0;
	cap=s;
}
void push(X data)
{
	if(size==cap)
		cout<<"stack size is full";
	a[++top]=data;
	size++;
}
X pop()
{
	if(size==0)
	{
		cout<<"stack is empty";
	}
	X val=a[top--];
	size--;
	return val;
}
int empty()
{
	if(size==0)
		return 0;
	else
		return 1;
}
int sizes()
{
	return size;
}

};
struct node
{
	int data;
	node* left;
	node* right;

};
struct node* root;
node* newnode(int data)
{
	struct node* temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}

void levelorder()
{
	stack <node*> s(10);
	struct node* current=root;
	s.push(current);
	//cout<<s.empty();
	int done=1;
	while(done)
	{

		while(current!=NULL)
		{
			if(current!=root)
			s.push(current);

			current=current->left;

		}
		if(s.empty()!=0)
		{
		node* asa=s.pop();
		cout<<asa->data<<" ";
		current=asa->right;
		}
		else
			done=0;
	}

}
int main() {
	root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->right->right=newnode(5);
	levelorder();
	return 0;
}
