#include "queue.h"
#include<iostream>
using namespace std;
class calldata
{
	public:
		int callnum;
		int arrivetime;
};
int main()
{
	QUEUE* que;
	que=createQueue();
	
	
	calldata *data=new calldata();
	data->arrivetime=10;
	data->callnum=10;
	enqueue(que,data);
	calldata* x;
	dequeue(que,(void**)&x);
	cout<<x->callnum;
	return 0;
	
}
