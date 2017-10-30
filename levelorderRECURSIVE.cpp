//============================================================================
// Name        : lis.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <math.h>
#include <queue>
struct node
{
	int data;
	struct node* right;
	struct node* left;
};
struct node* root;
struct node* newnode(int data)
{
	struct node* temp= new node;
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void inorder(struct node* temp)
{
	if(temp==NULL)
		return;
	inorder (temp->left);
	cout<<temp->data;

	inorder(temp->right);
}
int heightoftree(struct node* temp)
{
	if(temp==NULL)
		return 0;
   int lh=heightoftree(temp->left);
   int rh=heightoftree(temp->right);
   return max(lh,rh)+1;
}
void printlevel(int i,struct node* root)
{
	if(root==NULL)
		return;
	if(i==1)
	{
		cout<<root->data<<" ";
	}

	printlevel(i-1,root->left);

	printlevel(i-1,root->right);

}
void levelorder(int h,struct node* root)
{
	for(int i=1;i<=h;i++)
	{
		printlevel(i,root);
		cout<<endl;
	}
}

int main() {

	//root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	//inorder(root);
	int h=heightoftree(root);
	levelorder(h,root);
	return 0;
}
