#include <iostream>
#include <fstream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next; 	
}NODE;

int main()
{
	int filenum;
	cout<<"# 5-19 creating a list from the given files"<<endl;
	cout<<"PS:there are two files included"<<endl;
	cout<<"1) a.txt with data 100 200"<<endl;
	cout<<"2) b.txt with data 300"<<endl;
	cout<<"input the number of files ";
	cin>>filenum;
	NODE *array[filenum];
	string filename[filenum];
	for(int i=0;i<filenum;i++)
	{
		string tmp;
		cout<<"please input the whole file name (ex: a.txt) ";
		cin>>tmp;
		fstream file;
		file.open(tmp.c_str(),ios::in);
		filename[i]=tmp;
		if(!file)
		{
			cout<<"cannot open file please check the filename";
			exit(0);
		} 
		
		int data;
		NODE *head;
		NODE *pos;
		pos=new NODE();
		bool start=true;
		NODE *prev=NULL;
		int count=0;
		while(file>>data)
		{
			count++;
			NODE* pos=new NODE();
			pos->data=data;
			pos->next=NULL;
			if(start)
			{
				head=pos;
				start=false;
			}
			if(prev!=NULL)
				prev->next=pos;
			prev=pos;
		}
		array[i]=head;
	}
	
	for(int i=0;i<filenum;i++)
	{
		cout<<endl<<filename[i]<<" : ";
		NODE* ptr=array[i];
		while(ptr!=NULL)
		{
			cout<<ptr->data;
			ptr=ptr->next;
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
