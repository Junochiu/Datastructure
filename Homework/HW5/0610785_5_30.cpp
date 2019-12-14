#include<iostream>
#include<iomanip>
#include "0610785_5_30.h"
using namespace std;
int main()
{
	LIST *num1;
	num1=createList();
	LIST *num2;
	num2=createList();
	string str1,str2;
	cout<<"# 5-30 calculating big num "<<endl;
	//cout<<left<<setw(50)<<"plaese input the first big number";
	cin>>str1;
	//cout<<left<<setw(50)<<"plaese input the second big number";
	cin>>str2;
	for(int i=0;i<str1.length();i++)
	{
		int* data=(int*)malloc(sizeof(int));
		*data=(str1[i]-'0');
		addNode(num1,data);
	}
	for(int i=0;i<str2.length();i++)
	{
		int* data=(int*)malloc(sizeof(int));
		*data=(str2[i]-'0');
		addNode(num2,data);
	}
	LIST *ANS;
	ANS=createList();
	LIST *largerlist;
	largerlist=createList();
	int min,max;
	if(listCount(num1)>listCount(num2))
	{
		max=listCount(num1);
		largerlist=num1;
		min=listCount(num2);
	}
	else
	{
		max=listCount(num2);
		largerlist=num2;
		min=listCount(num1);
	} 
	for(int i=0;i<min;i++)
	{
		int *x,*y;
		traverse(num1,i,(void**)&x);
		traverse(num2,i,(void**)&y);
		*x=*(x)+*(y);
		addbackNode(ANS,x);
	}
	for(int i=min;i<max;i++)
	{
		int* x;
		traverse(largerlist,i,(void**)&x);
		addbackNode(ANS,x);
	}
	string countarray;
	int count=0;
	bool firstdigit = true;
	for(int i=0;i<listCount(ANS);i++)
	{
		if(!firstdigit)
		{
			countarray=(char)('0'+count)+countarray;
		}
		firstdigit=false;
		int* x;
		traverse(ANS,i,(void**)&x);
		if((*x)+count>=10)
		{
			*x=((*x)+count)%10;
			count=1;
		}
		else
		{
			*x=(*x)+count;
			count=0;
		}
		
	}
	if(count)
	{
		int* x=(int*)malloc(sizeof(int));
		(*x)=1;
		addbackNode(ANS,x);
	}
	string ans="";
	for(int i=0;i<listCount(ANS);i++)
	{
		int* x;
		traverse(ANS,i,(void**)&x);
		ans=(char)((*x)+'0')+ans;
	}
	//cout<<left<<setw(50)<<"answer after addition";
	cout<<ans<<endl;
	cout<<countarray;
	
}
