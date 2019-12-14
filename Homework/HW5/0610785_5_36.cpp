#include <iostream>
#include <fstream>
#include <iomanip>
#include "doublelist.h"
using namespace std;

typedef struct
{
	char Metropolitanarea[50];
	int population_2000;
	int population_1900;
}METRO;

int main()
{
	char t[50];
	fstream file;
	file.open("Metropolitan.txt",ios::in);
	LIST* list;
	list=createList();
	
	cout<<left<<setw(40)<<"Metropolitanarea";
	cout<<left<<setw(30)<<"population_1900";
	cout<<left<<setw(30)<<"population_2000";
	cout<<left<<endl;
	cout<<"______________________________________________________________________________________";
	cout<<endl;
	cout<<endl;
	
	if(!file)
	{
		cout<<"Can't open file";
		exit(0);
	}
	
	while(!file.eof())
	{
		METRO *metro = (METRO*) malloc(sizeof(METRO));
		if(!metro)
		{ 
			cout<<"out of memory";
			exit(0);
		}
		file.getline(metro->Metropolitanarea,sizeof(metro->Metropolitanarea),'/');
		file>>(metro->population_2000)>>(metro->population_1900);
		addNode(list,metro); 
	}
	for(int i=0;i<listCount(list);i++)
	{
		METRO* metro;
		nexttraverse(list,i,(void**)&metro);
		cout<<left<<setw(40)<<metro->Metropolitanarea;
		cout<<left<<setw(30)<<metro->population_1900;
		cout<<left<<setw(30)<<metro->population_2000;
	}
	for(int i=listCount(list)-1;i>=0;i--)
	{
		METRO* metro;
		prevtraverse(list,i,(void**)&metro);
		cout<<left<<setw(40)<<metro->Metropolitanarea;
		cout<<left<<setw(30)<<metro->population_1900;
		cout<<left<<setw(30)<<metro->population_2000;
		if(i==1)
			cout<<endl;
	}
	
		
}
