//selection sort
#include <iostream>
using namespace std;
int main()
{
	int num;
	int array[10];
	cout<<"enter 10 num";
	for(int i=0;i<10;i++)
		cin>>array[i];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(array[i]<array[j])
			{
				int tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}
	for(int i=0;i<10;i++)
		cout<<array[i]<<" ";
	return 0;
} 
