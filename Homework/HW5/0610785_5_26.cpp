#include <iostream>
#include <fstream>
#include <iomanip>
#include "0610785_5_26.h"
#include <string>
#include <cstdlib>
using namespace std;
typedef struct
{
	string name;
	LIST* score;
}STUDENT;

int main()
{
	fstream file;
	file.open("StudentInfo.txt",ios::in);
	if(!file)
	{
		cout<<"Can't open file";
		exit(0);
	}
	
	string firstname;
	string lastname;
	string name;
	LIST *list;
	list = createList();
	cout<<"# 5-26 input the score of students seperately"<<endl;
	cout<<"please input -1 to imply an empty data"<<endl;
	cout<<"when input score data please seperate by space"<<endl;
	cout<<"you can copy paste the score from Data.txt"<<endl;
	//cout<<"initialize"<<listCount(list);
	while(file>>firstname>>lastname)
	{
		STUDENT *newstu=new STUDENT();
		int tmp;
		int* score1 = (int*)malloc(sizeof(int));
		int* score2 = (int*)malloc(sizeof(int));
		int* score3 = (int*)malloc(sizeof(int));
		int* score4 = (int*)malloc(sizeof(int));
		name = firstname+" "+lastname;
		cout<<"please input score of "<<name<<endl;
		//cout<<"score1 =";
		cin>>(*score1);
		//cout<<"score2 =";
		cin>>(*score2);
		//cout<<"score3 =";
		cin>>(*score3);
		//cout<<"score4 =";
		cin>>(*score4);
		newstu->name=name;
		newstu->score=createList();
		addNode(newstu->score,score1);
		addNode(newstu->score,score2);
		addNode(newstu->score,score3);
		addNode(newstu->score,score4);
		addNode(list,newstu);
	}

	cout<<left<<setw(20)<<"name"<<left<<setw(10)<<"score1";
	cout<<left<<setw(10)<<"score2"<<left<<setw(10)<<"score3"<<left<<setw(10)<<"score4";
	cout<<left<<setw(10)<<"total"<<left<<setw(10)<<"average"<<endl;
	for(int i=0;i<listCount(list);i++)
	{
		STUDENT* stu;
		traverse(list,i,(void**)&stu);
		float sum=0;
		float count=0;
		cout<<left<<setw(20)<<stu->name;
		for(int j=0;j<listCount(stu->score);j++)
		{	
			int* s;
			traverse(stu->score,j,(void**)&s);
			if((*s)!=-1)
			{
				cout<<left<<setw(10)<<(*s)<<" ";
				sum+=(*s);
				count++;
			}
			else
			{
				cout<<left<<setw(10)<<"  ";
			}	
		}
		cout<<left<<setw(10)<<sum;
		cout<<left<<setw(10)<<(sum/count)<<endl;
	}
	return 0;
}
