#include<iostream>
#include <bits/stdc++.h>
#include "0610785_9_30.h"
using namespace std;
int compare(void* a,void* b)
{
	int int_a,int_b;
	int_a=*(int*)a;
	int_b=*(int*)b;
	if(int_a<int_b)
		return -1;
	else if(int_a>int_b)
		return 1;
	else 
		return 0;
}
void measurereheapup(HEAP *heap,int size)
{
	double sum=0;
	for(int i=1;i<=size;i++)
	{
		int* tmp=new int();
		*tmp=i;
		int count=0;
		heapInsert(heap,tmp,count);
		sum+=count;
	} 
	cout<<"== reheap up =="<<endl;
	cout<<"total steps = "<<sum<<endl;
	cout<<"average steps = "<<(sum/(double)size)<<endl;
	cout<<"O(logN) N ="<<size<<" : "<<log(size)<<endl;
}
void measurereheapdown(HEAP *heap,int size)
{
	double sum=0;
	for(int i=1;i<=size;i++)
	{
		int count=0;
		int** data;
		heapDelete(heap,(void**) data,count);
		sum+=count;
	} 
	cout<<"== reheap down =="<<endl;
	cout<<"total steps = "<<sum<<endl;
	cout<<"average steps = "<<(sum/(double)size)<<endl;
	cout<<"O(logN) N ="<<size<<" : "<<log(size)<<endl;
}
int main()
{
	cout<<"----------------------------100-----------------------------\n";
	HEAP* heap=heapCreate(100,compare);
	measurereheapup(heap,100);
	measurereheapdown(heap,100);
	cout<<"----------------------------200-----------------------------\n";
	heap=heapCreate(200,compare);
	measurereheapup(heap,200);
	measurereheapdown(heap,200);
	cout<<"----------------------------500-----------------------------\n";
	heap=heapCreate(500,compare);
	measurereheapup(heap,500);
	measurereheapdown(heap,500);
	cout<<"----------------------------1000----------------------------\n";
	heap=heapCreate(1000,compare);
	measurereheapup(heap,1000);
	measurereheapdown(heap,1000);
	cout<<"----------------------------2000----------------------------\n";
	heap=heapCreate(2000,compare);
	measurereheapup(heap,2000);
	measurereheapdown(heap,2000);
	return 0;
}
