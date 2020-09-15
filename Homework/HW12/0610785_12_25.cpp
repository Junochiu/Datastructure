#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <stdlib.h>
using namespace std;
void merge(vector<int> &arr,int start,int mid,int end)
{
	vector<int> leftsub(arr.begin()+start,arr.begin()+mid+1),
				rightsub(arr.begin()+mid+1,arr.begin()+end+1);
	leftsub.push_back(INT_MAX);
	rightsub.push_back(INT_MAX);
	int leftidx=0,rightidx=0;
	for(int i=start;i<=end;i++)
	{
		if(leftsub[leftidx]<=rightsub[rightidx])
		{
			arr[i]=leftsub[leftidx];
			leftidx++;
		}
		else
		{
			arr[i]=rightsub[rightidx];
			rightidx++;
		}
	}
	
}
void sortlesssort(vector<int> &arr,int start,int end)
{
	if(start<end)
	{
		int mid=((start+end)/2);
		sortlesssort(arr,start,mid);
		sortlesssort(arr,mid+1,end);	
		merge(arr,start,mid,end);
	}		
}
int main()
{
	srand(time(NULL));
	vector<int> arr;
	cout<<"# 12-25 \nrandom 範圍為 0-1000\n排序後資料將由左而右，由上而下排\n";
	cout<<"array data before sort : \n";
	for(int i=0;i<20;i++)
	{
		arr.push_back(rand()%1000);	
		cout<<setw(5)<<arr[i]<<" ";
		if((i+1)%10==0)
			cout<<endl;
	} 
	cout<<endl;
	sortlesssort(arr,0,19);
	cout<<"array data after sort : \n";
	for(int i=0;i<20;i++)
	{
		cout<<setw(5)<<arr[i]<<" ";
		if((i+1)%10==0)
			cout<<endl;
	}
	return 0;
} 
