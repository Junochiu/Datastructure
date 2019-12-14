#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct node
{
	void* dataPtr;
	struct node* next;
	struct node* prev;
}NODE;

typedef struct
{
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
}LIST;

static bool _insert(LIST* pList,NODE* pPre,void* dataInPtr)
{
	NODE* pNew;
	if(!(pNew=(NODE*)malloc(sizeof(NODE))))
	{
		return false;	
	}
	
	pNew->dataPtr=dataInPtr;
	pNew->next=NULL;
	if(pPre==NULL)
	{
		pNew->next=pList->head;
		if(pList->head!=NULL)
			pList->head->prev=pNew;
		pList->head=pNew;
		pNew->prev=NULL;
		if(pList->count==0)
			pList->rear=pNew;
	}
	else
	{
		pNew->next=NULL;
		pPre->next=pNew;
		pNew->prev=pPre;
		pList->rear=pNew; 
	}
	(pList->count)++;
	return true;
}

LIST* createList()
{
	LIST* list;
	list = (LIST*)malloc(sizeof(LIST));
	if(list)
	{
		list->head=NULL;
		list->pos=NULL;
		list->rear=NULL;
		list->count=0;
	}
	return list;
}

int addNode (LIST* pList, void* dataInPtr)
{
	bool found;
	bool success;
	NODE* pPre;
	NODE* pLoc;
	success = _insert(pList,pList->rear,dataInPtr);
	if(!success)
		return(-1);
	return 0;
	
}

bool searchList(LIST* pList,void* pArgu,void** pDataOut)
{
	bool found;
	NODE* pPre;
	NODE* pLoc;
	if(found)
		*pDataOut = pLoc->dataPtr;
	else
		*pDataOut = NULL;
	return found;
}

bool emptyList(LIST* pList)
{
	return (pList->count == 0);
}

bool fullList(LIST* pList)
{
	NODE* temp;
	if((temp = (NODE*)malloc(sizeof(*pList->head))))
	{
		free(temp);
		return false;
	}
	return true;
}

int listCount(LIST* pList)
{
	return pList->count;
}

bool nexttraverse (LIST* pList, int fromWhere, void** dataPtrOut)
{
	if(pList->count==0)
		return false;
	if(fromWhere ==0)
	{
		pList->pos=pList->head;
		*dataPtrOut = pList->pos->dataPtr;
		return true; 
	}
	else
	{
		if(pList->pos->next==NULL)
		return false;
		else
		{
			pList->pos = pList->pos->next;
			*dataPtrOut = pList->pos->dataPtr;
		}
		return true;
	}
}

bool prevtraverse (LIST* pList, int fromWhere, void** dataPtrOut)
{
	if(pList->count==0)
		return false;
	if(fromWhere == ((pList->count)-1))
	{
		pList->pos=pList->rear;
		*dataPtrOut = pList->pos->dataPtr;
		return true; 
	}
	else
	{
		if(pList->pos->prev==NULL)
		return false;
		else
		{
			pList->pos = pList->pos->prev;
			*dataPtrOut = pList->pos->dataPtr;
		}
		return true;
	}
}

LIST* destroyList(LIST* pList)
{
	NODE* deletePtr;
	if(pList)
	{
		while(pList->count>0)
		{
			free(pList->head->dataPtr);
			deletePtr = pList->head;
			pList->head = pList->head->next;
			pList->count--;
			free(deletePtr);
		}
		free (pList);
	}
	return NULL;
}

