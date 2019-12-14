/*
DATASTRUCTURE HW1

This is a project take a file which include student ID and avg score as input
intends to output the result after sort (I choose avg score as the item for comparing)

The structure of NODE:
NODE include studentinfo class, which record the studentid and student avg score,
and a pointer link. 
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class Studentinfo
{
	public:
		int id;
		float score; 
		Studentinfo(int id,float score)
		{
			this->id=id;
			this->score=score;
		}
};

typedef struct node
{
	void* dataPtr;
	struct node* link;	
}NODE;

NODE* createNode (void* itemPtr)
{
	NODE* nodePtr;
	nodePtr = (NODE*)malloc(sizeof(NODE));
	nodePtr->dataPtr=itemPtr;
	nodePtr->link=NULL;
	return nodePtr;	
}

int compare(void* ptr1,void* ptr2)
{
	if(*(float*)ptr1>=*(float*)ptr2)
		return 1;
	else 
		return 0;
}

int main()
{
	fstream file;
	file.open("StudentInfo.txt",ios::in);
	if(!file)
	{
		cout<<"Can't open file";
		exit(0);
	}
	NODE* head=NULL;
	NODE* index;
	NODE* pre;
	int id;
	float score;
	while(file>>id>>score)
	{
		Studentinfo *stu=new Studentinfo(id,score);
		pre=NULL;
		index=head;
		NODE* tmp=createNode(stu);
		if(head==NULL)
			head=tmp;
			
		else
		{
			if(compare(&static_cast <Studentinfo*> (head->dataPtr)->score,&static_cast <Studentinfo*> (tmp->dataPtr)->score))
			{
				tmp->link=head;
				head=tmp;
			}
			else
			{
				while(index && compare(&static_cast <Studentinfo*> (tmp->dataPtr)->score,&static_cast <Studentinfo*> (index->dataPtr)->score))
				{
					pre=index;
					index=index->link;
				}
				tmp->link=index;
				pre->link=tmp;
			}
			
		}
	}
	index=head;
	cout<<setw(15)<<setiosflags(ios::left)<<"stu id";
	cout<<setw(3)<<setiosflags(ios::left)<<"avg"<<endl;
	cout<<"-------------------------"<<endl;
	while(index)
	{
		cout<<setw(15)<<setiosflags(ios::left)<<static_cast <Studentinfo*>(index->dataPtr)->id;
		cout<<setw(3)<<setiosflags(ios::left)<<static_cast <Studentinfo*>(index->dataPtr)->score<<endl;
		index=index->link;
	}
	return 0;	
} 
