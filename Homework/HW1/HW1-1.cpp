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
			if(stu->score < static_cast <Studentinfo*> (head->dataPtr)->score)
			{
				tmp->link=head;
				head=tmp;
			}
			else
			{
				while(index && (stu->score > static_cast <Studentinfo*> (index->dataPtr)->score))
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
