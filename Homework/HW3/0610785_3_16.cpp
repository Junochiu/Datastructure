#include <iostream>
#include "0610785_3_16.h"
using namespace std;
int main()
{
	int num;
	int *dataptr;
	STACK* stack;
	stack=createStack();
	cout<<"#3-16"<<endl;
	cout<<"please input a sequence of number, use ^D to imply end of file"<<endl;
	cout<<"Once ENTER is pressed the program will start running"<<endl;
	cout<<"ex:1 2 3 4 5 -1 1 2 3 4 5 6 7 8 9 10 -2 11 12 -3 1 2 3 4 5 ^D"<<endl;
	while(cin>>num)
	{
		if(num>=0)
		{
			dataptr=(int*)malloc(sizeof(int));
			*dataptr=num;
			pushStack(stack,dataptr);
		}
			
		else
		{
			if(stackCount(stack)<5)
			{
				cout<<"Stack size < 5";
				return 0;
			}
			
			else
			{
				for(int i=0;i<5;i++)
				{
					cout<<*(int*)popStack(stack)<<" ";		
				}
				cout<<endl;
			}
		}
	}
	while(!emptyStack(stack))
	{
		cout<<*(int*)popStack(stack)<<" ";
	}
	return 0;
 } 
