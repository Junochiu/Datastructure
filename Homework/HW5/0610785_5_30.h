#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct node
{
	void* dataPtr;
	struct node* link;
}NODE;

typedef struct
{
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
}LIST;

void _delete(LIST* pList, NODE* pPre,NODE* pLoc,void** dataOutPtr)
{
	*dataOutPtr = pLoc->dataPtr;
	if(pPre == NULL)
		pList->head = pLoc->link;
	else
		pPre->link=pLoc->link;
	if(pLoc->link == NULL)
		pList->rear=pPre;
	(pList->count)--;
	free(pLoc);
	return;
}

static bool _insert(LIST* pList,NODE* pPre,void* dataInPtr)
{
	NODE* pNew;
	if(!(pNew=(NODE*)malloc(sizeof(NODE))))
		return false;
	pNew->dataPtr=dataInPtr;
	pNew->link=NULL;
	if(pPre==NULL)
	{
		pNew->link=pList->head;
		pList->head=pNew;
		if(pList->count==0)
			pList->rear=pNew;
	}
	else
	{
		pNew->link=pPre->link;
		pPre->link=pNew;
		if(pNew->link==NULL)
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
	bool success;
	NODE* pPre;
	NODE* pLoc;
	success = _insert(pList,NULL,dataInPtr);
	if(!success)
		return(-1);
	return 0;
	
}

int addbackNode (LIST* pList, void* dataInPtr)
{
	bool success;
	NODE* pPre;
	NODE* pLoc;
	
	success = _insert(pList,pList->rear,dataInPtr);
	if(!success)
		return(-1);
	return 0;
	
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

bool traverse (LIST* pList, int fromWhere, void** dataPtrOut)
{
	if(pList->count==0)
		return false;
	if(fromWhere ==0 )
	{
		pList->pos=pList->head;
		*dataPtrOut = pList->pos->dataPtr;
		return true; 
	}
	else
	{
		if(pList->pos->link==NULL)
		return false;
		else
		{
			pList->pos = pList->pos->link;
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
			pList->head = pList->head->link;
			pList->count--;
			free(deletePtr);
		}
		free (pList);
	}
	return NULL;
}

