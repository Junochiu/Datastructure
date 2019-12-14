#include <iostream>
#include <fstream>
#include <iomanip>
#include "0610785_5_29.h"
using namespace std;
typedef struct
{
	int coi;
	int exp;	
}TERM;

int compare(void* term1,void* term2)
{
	int exp1=((TERM*)term1)->exp;
	int exp2=((TERM*)term2)->exp;
	if(exp1>exp2)
		return 1;
	else if(exp1<exp2)
		return -1;
	else
		return 0;
}

int main()
{
	cout<<"# 5 - 29"<<endl;
	cout<<"read the polynomial from the polynomial1.txt and polynomial2.txt file seperately,"<<endl;
	cout<<"and output the result of adding the two polynomial using linked list."<<endl;
	cout<<"the output format (x,y) where x is the coefficient and y indicates the exponential term."<<endl;
	cout<<endl;
	//read the first polynomial from file
	fstream p1;
	p1.open("polynomial1.txt",ios::in);
	if(!p1)
	{
		cout<<"can't open file";
		exit(0);
	}
	
	//read the second polynomial from file
	fstream p2;
	p2.open("polynomial2.txt",ios::in);
	if(!p2)
	{
		cout<<"can't open file";
		exit(0);
	}
	
	//create the first polynomial list
	LIST* poly1;
	poly1 = createList(compare);
	int coi,exp;
	while(p1>>coi>>exp)
	{
		TERM *newTERM = (TERM*) malloc(sizeof(TERM));
		newTERM->coi=coi;
		newTERM->exp=exp;
		addNode(poly1,newTERM);
		
	}	
	cout<<"polynomial 1 : ";
	for(int i=0;i<listCount(poly1);i++)
	{
		TERM *t;
		traverse(poly1,i,(void**)&t);
		cout<<" ("<<t->coi<<","<<t->exp<<") ";
	}
	cout<<endl;
	//create the second polynomial list
	LIST* poly2;
	poly2 = createList(compare);
	while(p2>>coi>>exp)
	{
		TERM *newTERM = (TERM*) malloc(sizeof(TERM));
		newTERM->coi=coi;
		newTERM->exp=exp;
		addNode(poly2,newTERM);
	}
	cout<<"polynomial 2 : ";
	for(int i=0;i<listCount(poly2);i++)
	{
		TERM *t;
		traverse(poly2,i,(void**)&t);
		cout<<" ("<<t->coi<<","<<t->exp<<") ";
	}
	cout<<endl;
	//create the ans polynomial list for data saving
	LIST* ans;
	ans = createList(compare);
	TERM* t1;
	traverse(poly1,0,(void**)&t1);
	TERM* t2;
	traverse(poly2,0,(void**)&t2);
	while((!emptyList(poly1))&&(!emptyList(poly2)))
	{
		if((t1->exp)<(t2->exp))
		{
			addNode(ans,t1);
			removeNode(poly1,t1,(void**)&t1);
			traverse(poly1,0,(void**)&t1);
		}
		else if((t1->exp)>(t2->exp))
		{
			addNode(ans,t2);
			removeNode(poly2,t2,(void**)&t2);
			traverse(poly2,0,(void**)&t2);
		}
		else
		{
			TERM *newTERM = (TERM*) malloc(sizeof(TERM));
			newTERM->coi=t1->coi+t2->coi;
			newTERM->exp=t1->exp;
			if(newTERM->coi!=0)
				addNode(ans,newTERM);
			removeNode(poly1,t1,(void**)&t1);
			traverse(poly1,0,(void**)&t1);
			removeNode(poly2,t2,(void**)&t2);
			traverse(poly2,0,(void**)&t2);
		}
	}
	if(!emptyList(poly1))
	{
		TERM* t1;
		traverse(poly1,0,(void**)&t1);
		addNode(ans,t1);
		removeNode(poly1,t1,(void**)&t1);
	}
	else if(!emptyList(poly2))
	{
		TERM* t2;
		traverse(poly2,0,(void**)&t2);
		addNode(ans,t2);
		removeNode(poly2,t2,(void**)&t2);
	}
	cout<<"polynomial after addition : ";
	for(int i=0;i<listCount(ans);i++)
	{
		traverse(ans,i,(void**)&t2);
		cout<<" ("<<t2->coi<<","<<t2->exp<<") ";
	}
	

}
