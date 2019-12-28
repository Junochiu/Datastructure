#include <iostream>
#include "0610785_7_23.h"
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
typedef struct
{
	string name;
	string phone;
}DATA;
int compare (void* a,void* b)
{
	DATA* dataa;
	DATA* datab;
	dataa = (DATA*)a;
	datab = (DATA*)b;
	return strcmp((dataa->name).c_str(),(datab->name).c_str());	
}

void add (BST_TREE* tree);
void delet (BST_TREE* tree);
void find (BST_TREE* tree);
void printtree (BST_TREE* tree);
int main()
{
	fstream file;
	file.open("0610785_7_23.txt",ios::in);
	if(!file)
		cout<<"cannot open file";
	string name;
	string phone;
	BST_TREE* tree;
	tree = BST_Create(compare);
	while(file>>name>>phone)
	{
		//cout<<name<<" "<<phone<<endl;
		DATA* newdata = new DATA();
		newdata->name = name;
		newdata->phone = phone;
		BST_Insert(tree,newdata);
	}
	int choice;
	cout<<"# 7_23 implement student data func with array \n";
	while(1)
	{
		cout<<"===============================================================================\n";
		cout<<"enter the corresponding number for function \n";
		cout<<"1 add a student data\n";
		cout<<"2 find a student data\n";
		cout<<"3 delete a student data\n";
		cout<<"4 print all data\n";
		cout<<"5 end the program\n";
		cout<<"===============================================================================\n";
		cout<<"input the number : ";
		cin>>choice;
		switch (choice)
		{
			case 1 :
				add(tree);
				break;
			case 2 :
				find(tree);
				break;
			case 3 :
				delet(tree);
				break;
			case 4 :
				printtree(tree);
				break;
			case 5 :
				return 0;
		}
	}

	return 0;	
}
void add (BST_TREE* tree)
{
	fstream file;
	file.open("0610785_7_23.txt",ios::app);
	DATA *newdata = new DATA();
	//cout<<"adding new data----------------------------------------------------------------------\n";
	cout<<"input student name : ";
	cin>>newdata->name;
	cout<<"input student phone number : ";
	cin>>newdata->phone;
	BST_Insert(tree,newdata);
	file<<endl<<newdata->name<<" "<<newdata->phone;
}
void writedataintofile(void* data)
{
	DATA *tmpdata;
	tmpdata = (DATA*)data;
	fstream file;
	file.open("0610785_7_23.txt",ios::app);
	file<<tmpdata->name<<" "<<tmpdata->phone<<endl;
}
void delet (BST_TREE* tree)
{
	string deletename;
	//cout<<"delete--------------------------------------------------------------------------------\n";
	cout<<"please input the student name you wanted to delete : ";
	cin>>deletename;
	if(!BST_Delete(tree,&deletename))
		cout<<"the name is not on the list \n";
	else
	{
		cout<<"the list after delete\n";
		printtree(tree);
	}
	fstream file;
	file.open("0610785_7_23.txt",ios::out);
	file<<"";
	BST_Traverse(tree,writedataintofile);
}
void find (BST_TREE* tree)
{
	string findname;
	//cout<<"look up-------------------------------------------------------------------------------\n";
	cout<<"input the name you want to look up : ";
	cin>>findname;
	DATA* finddata = (DATA*)BST_Retrieve(tree, &findname);
	if(finddata)
	{
		cout<<"name : "<<finddata->name<<endl;
		cout<<"phone : "<<finddata->phone<<endl;
	}
	else
		cout<<"cannot find this guy\n";
}
void processdata (void* data)
{
	DATA *tmpdata;
	tmpdata = (DATA*)data;
	cout<<setw(8)<<tmpdata->name<<setw(15)<<tmpdata->phone<<endl;
}
void printtree(BST_TREE* tree)
{
	//cout<<"print all------------------------------------------------------------------------------\n";
	BST_Traverse(tree,processdata);
}


