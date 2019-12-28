#include<iostream>
using namespace std;
typedef struct node
{
	node* left;
	node* right;
	char data;
}NODE;

void preorder(NODE* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	} 
}
 
int main()
{
	char initdata[5]={'A','C','E','B','D'};
	NODE* root = new NODE();
	root->left=NULL;
	root->right=NULL;
	root->data=initdata[0];

	NODE* walkingnode = new NODE();
	walkingnode->data=initdata[1];
	walkingnode->right=NULL;
	walkingnode->left=NULL;
	root->left=walkingnode;	
	
	walkingnode = new NODE();
	walkingnode->data=initdata[2];
	walkingnode->right=NULL;
	walkingnode->left=NULL;
	root->right=walkingnode;	
	
	walkingnode = new NODE();
	walkingnode->data=initdata[3];
	walkingnode->right=NULL;
	walkingnode->left=NULL;
	root->left->left=walkingnode;
	
	walkingnode = new NODE();
	walkingnode->data=initdata[4];
	walkingnode->right=NULL;
	walkingnode->left=NULL;
	root->left->right=walkingnode;
	
	preorder(root);
} 
