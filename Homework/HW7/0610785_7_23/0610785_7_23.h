#include <stdbool.h>
#include <iostream>
#include <stdlib.h>
#define SIZE 100
using namespace std;
typedef struct
	{
	 int   count;
	 int  (*compare) (void* argu1, void* argu2);
	 void*  root[SIZE];
	} BST_TREE;
	BST_TREE* BST_Create 
	         (int (*compare) (void* argu1, void* argu2));
	bool  BST_Insert   (BST_TREE* tree, void* dataPtr);
	bool  BST_Delete   (BST_TREE* tree, void* dltKey);
	void* BST_Retrieve (BST_TREE* tree, void* keyPtr);
	void  BST_Traverse (BST_TREE* tree,
	                    void (*process)(void* dataPtr));

	bool BST_Empty (BST_TREE* tree);
	int  BST_Count (BST_TREE* tree);

BST_TREE* BST_Create(int (*compare) (void* argu1, void* argu2))
{
	BST_TREE* tree;
	tree = (BST_TREE*) malloc (sizeof (BST_TREE));
	if (tree)
	   {
	    tree->count   = 0;
	    tree->compare = compare;
	   }

	return tree;
}
bool BST_Insert (BST_TREE* tree, void* dataPtr)
{
	tree->root[tree->count]=(void*)malloc(sizeof(dataPtr));
	int i=0;
	while((i < tree->count) && (tree->compare(dataPtr,tree->root[i]) > 0) )
	{
		i++;	
	}
	for(int j=tree->count;j>=i;j--)
	{
		tree->root[j+1]=tree->root[j];
	}
	tree->root[i]=dataPtr;
	(tree->count)++;
	return true;
}  
bool BST_Delete (BST_TREE* tree, void* dltKey)
{
	bool  success=false;
	if(tree->count==0)
		return success;
	for(int i=0;i<tree->count;i++)
	{
		if(tree->compare(dltKey, tree->root[i])==0)
		{
			for(int j=i;j<(tree->count)-1;j++)
			{
				tree->root[j]=tree->root[j+1];
			}
			//free(tree->root[(tree->count)]);
			(tree->count)--;
			success=true;
			return success;
		}
	}
	return success;
}

void* BST_Retrieve  (BST_TREE* tree, void* keyPtr)
{
	if(tree->count!=0)
	{
		for(int i=0;i<tree->count;i++)
		{
			if(tree->compare(keyPtr,tree->root[i])==0)
				return tree->root[i];
		}
		return NULL;
	}
	else
		return NULL;
	
}	
void BST_Traverse (BST_TREE* tree, 
                   void (*process) (void* dataPtr)) 
{
	for(int i=0;i<tree->count;i++)
		process(tree->root[i]);
	return;
}

bool BST_Empty (BST_TREE* tree)
{
	return (tree->count == 0);
}	

int BST_Count (BST_TREE* tree)
{
	return (tree->count);
}

