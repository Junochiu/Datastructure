#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int num;
	stack<int> Stack;
	cout<<"#3-16"<<endl;
	cout<<"please input a sequence of number, use ^D to imply end of file"<<endl;
	cout<<"Once ENTER is pressed the program will start running"<<endl;
	cout<<"ex:1 2 3 4 5 -1 1 2 3 4 5 6 7 8 9 10 -2 11 12 -3 1 2 3 4 5 ^D"<<endl;
	while(cin>>num)
	{
		if(num>=0)
			Stack.push(num);
		else
		{
			if(Stack.size()<5)
			{
				cout<<"Stack size < 5";
				return 0;
			}
			
			else
			{
				for(int i=0;i<5;i++)
				{
					cout<<Stack.top()<<" ";
					Stack.pop();		
				}
				cout<<endl;
			}
		}
	}
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
	return 0;
 } 
