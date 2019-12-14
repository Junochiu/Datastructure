#include <iostream>
#include <stdlib.h>
#include <string>
#include "0610785_3_24.h"

using namespace std;

class SPOT
{
	public:
		int x;
		int y;
		SPOT(int x,int y){this->x=x;this->y=y;}
		void print()
		{
			cout<<"("<<(this->x)+1<<","<<(this->y)+1<<")";
		}
		
};

int main()
{
	cout<<"#3-25"<<endl;
	cout<<"this is a maze of size 10X12"<<endl;
	int map[10][12]={
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,1,0,1,0,1,0,1},
	{1,1,1,0,1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,1,1,1,0,1},
	{1,1,0,1,1,1,1,1,1,1,0,0},
	{1,1,0,1,0,1,1,1,1,1,1,1},
	{1,1,0,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1,1,0,1,0,1},
	{1,1,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
	};

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<12;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	cout<<"1 stands for wall and 0 stands for road"<<endl;
	
	char reply;
	do
	{
		int x,y;
		bool isentry=false;
		SPOT *en=new SPOT(-1,-1);
	
		while(!isentry)
		{
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			x-=1;
			y-=1;
			en->x=x;
			en->y=y;
			if(map[x][y]==0)
				isentry=true;
			
		}
		//cout<<"isentry"<<endl;
		
		SPOT* curr=new SPOT(en->x,en->y);
		SPOT* last=new SPOT(-1,-1);
		SPOT* deci=new SPOT(-1,-1);
		STACK* visitedstack;
		STACK* alterstack;
		visitedstack=createStack();
		alterstack=createStack();
		
		bool start=true;
		bool gameover=false;
		while(((curr->x!=4)||(curr->y!=11))&&!gameover)
		{
			cout<<"current spot : ";
			curr->print();
			cout<<endl;
			
			pushStack(visitedstack,curr);
			int count=0;
			if(((curr->x)-1>=0)&&(map[(curr->x)-1][(curr->y)]==0))
			{
				//cout<<"("<<(curr->x)-1<<","<<(curr->y)<<")";
				//last->print();
				//cout<<((curr->x)-1!=(last->x)||(curr->y)!=(last->y));
				if(((curr->x)-1!=(last->x)||(curr->y!=last->y)))
				{
					SPOT* next=new SPOT((curr->x)-1,curr->y);
					pushStack(alterstack,next);
					count++;
				}	
			}
			if(((curr->y)-1>=0)&&(map[(curr->x)][(curr->y)-1]==0))
			{
				//cout<<"("<<(curr->x)<<","<<(curr->y)-1<<")";
				//last->print();
				//cout<<((curr->x)!=(last->x)||((curr->y)-1!=(last->y)));
			
				if(((curr->x)!=(last->x)||((curr->y)-1!=(last->y))))
				{	
				
					SPOT* next=new SPOT((curr->x),(curr->y)-1);
					pushStack(alterstack,next);
					count++;
				}
			
			}
			if(((curr->x)+1<12)&&(map[(curr->x)+1][(curr->y)]==0))
			{
				//cout<<"("<<(curr->x)+1<<","<<(curr->y)<<")";
				//last->print();
				//cout<<((curr->x)+1!=(last->x)||((curr->y)!=(last->y)));
				
				if(((curr->x)+1!=(last->x)||((curr->y)!=(last->y))))
				{	
					SPOT* next=new SPOT((curr->x)+1,(curr->y));
					pushStack(alterstack,next);
					count++;
				}
			}
			if(((curr->y)+1<12)&&(map[(curr->x)][(curr->y)+1]==0))
			{
				//cout<<"("<<(curr->x)<<","<<(curr->y)+1<<")";
				//last->print();
				//cout<<((curr->x)!=(last->x)||((curr->y)+1!=(last->y)));
				
				if(((curr->x)!=(last->x)||((curr->y)+1!=(last->y))))
				{	
					SPOT* next=new SPOT((curr->x),(curr->y)+1);
					pushStack(alterstack,next);
					count++;
				}
			}
			if(start)
			{
				start=false;
				if(count==0)
				{
					cout<<"gameover"<<endl;
					gameover=true;
					continue;
				}
				else if(count==1)
				{
					curr=(SPOT*)popStack(alterstack);
				}
				else
				{
					curr=(SPOT*)popStack(alterstack);
					pushStack(visitedstack,deci);
				}	
			}
			
			else
			{
				if(count==0)
				{ 
					cout<<"no road anymore, start to back track"<<endl;
					SPOT* tmp=(SPOT*)popStack(visitedstack);
					while((tmp->x!=-1)&&(tmp->y!=-1)&&!gameover)
					{	
						if(emptyStack(visitedstack))
						{
							cout<<"backtrack";
							tmp->print();
							cout<<endl;
							cout<<"gameover"<<endl;
							gameover=true;
							continue;
						}	
						cout<<"backtrack";
						tmp->print();
						cout<<endl;
						tmp=(SPOT*)popStack(visitedstack);
					}
					if(tmp->x==-1&&tmp->y==-1)
					{
						tmp=(SPOT*)stackTop(visitedstack);
						cout<<"backtrack";
						tmp->print();
						cout<<endl;
						curr=(SPOT*)popStack(alterstack);
						cout<<endl<<"start new path from";
						curr->print();
						cout<<endl;
					}
					
				}
				else if(count==1)
				{
					curr=(SPOT*)popStack(alterstack);
				}
				else
				{
					curr=(SPOT*)popStack(alterstack);
					pushStack(visitedstack,deci);
				}
			}
			
			if(!gameover)
			{
				last=(SPOT*)stackTop(visitedstack);
				if(last->x==-1 &&last->y==-1)
				{
					SPOT* t=(SPOT*)popStack(visitedstack);
					last=(SPOT*)stackTop(visitedstack);
					pushStack(visitedstack,t);
				}
			}
				
		}
		
		
		STACK* answerstack;
		answerstack=createStack();
		
		cout<<endl;
		if((curr->x==4)&&(curr->y==11))
		{
			cout<<"congrats! you reacded to the cheese!!!"<<endl;
		//	cout<<"the final path (backtrack style) = ";
			cout<<endl;
		//	curr->print();
			pushStack(answerstack,curr);
		
			while(!emptyStack(visitedstack))
			{
				if((((SPOT*)stackTop(visitedstack))->x!=-1) && (((SPOT*)stackTop(visitedstack))->y!=-1))
				{
					pushStack(answerstack,(SPOT*)stackTop(visitedstack));
					((SPOT*)popStack(visitedstack));
				}
				else
				{
					popStack(visitedstack);
				}
			}
			cout<<endl<<"the final path (forward style) = ";
			cout<<endl;
			while(!emptyStack(answerstack))
				{
					((SPOT*)popStack(answerstack))->print();
					cout<<"->";
				}cout<<"EXIT";
		}	
		
		
		
		else
		{
			cout<<"Oops, no cheese for you";
		}
		
		cout<<endl<<"Enter y to play again";
		cin>>reply;
	}while(reply=='y'||reply=='Y');
	
}
